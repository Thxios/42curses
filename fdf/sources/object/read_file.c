/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:55:29 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/05 19:01:56 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object/read_file.h"
#include "utils/any_array.h"
#include "utils/ptr_array.h"
#include "utils/utils.h"
#include "libft.h"
#include "config.h"

void	delete_map_info(t_map_info *map)
{
	int	row;

	row = 0;
	while (row < map->n_row)
	{
		free(map->height[row]);
		row++;
	}
	free(map->height);
	free(map);
}

t_map_info	*parse_file(int fd)
{
	char		*line;
	char		**splited;
	t_ptr_arr	*arr;
	t_map_info	*map;
	int			idx;
	int			n_col;

	arr = new_ptr_array();
	while (1)
	{
		line = ft_readline(fd);
		if (!line)
			break;
		push_ptr_array(arr, line);
	}
	if (arr->size == 0)
	{
		delete_ptr_array(arr);
		return (NULL);
	}
	map = safe_calloc(1, sizeof(t_map_info));
	map->n_row = arr->size;
	map->height = safe_calloc(map->n_row, sizeof(int *));
	map->height[0] = map_atoi_to_splited(arr->arr[0], &map->n_col);
	if (map->n_col == 0)
	{
		delete_ptr_array(arr);
		delete_map_info(map);
		return (NULL);
	}
	idx = 1;
	while (idx < arr->size) {
		map->height[idx] = map_atoi_to_splited(arr->arr[1], &n_col);
		if (n_col != map->n_col)
		{
			delete_ptr_array(arr);
			delete_map_info(map);
			return (NULL);
		}
	}
	delete_ptr_array(arr);
	return (map);
}

int	rc_to_idx(int row, int col, int n_row)
{
	return (row * n_row + col);
}

void	init_obj_edges(t_obj3d *obj, t_map_info *info)
{
	int	r;
	int	c;
	int	e_idx;

	e_idx = 0;
	r = 0;
	while (r < info->n_row)
	{
		c = 0;
		while (c < info->n_col)
		{
			if (r > 0)
			{
				obj->e[e_idx].st = rc_to_idx(r - 1, c, info->n_row);
				obj->e[e_idx++].ed = rc_to_idx(r, c, info->n_row);
			}
			if (c > 0)
			{
				obj->e[e_idx].st = rc_to_idx(r, c - 1, info->n_row);
				obj->e[e_idx++].ed = rc_to_idx(r, c, info->n_row);
			}
			c++;
		}
		r++;
	}
}

void	init_obj_vertices(t_obj3d *obj, t_map_info *info)
{
	int				r;
	int				c;
	int				v_idx;
	double			gap;
	t_color_grad	grad;

	gap = clipf(10. / maxf(info->n_col, info->n_row), 0.1, 5);
	// offset_x = ((double)(info->n_row - 1) / 2) * gap;
	// offset_y = ((double)(info->n_col - 1) / 2) * gap;
	grad = make_grad(0x0000ff, 0xff0000);
	r = 0;
	while (r < info->n_row)
	{
		c = 0;
		while (c < info->n_col)
		{
			v_idx = rc_to_idx(r, c, info->n_row);
			obj->v[v_idx].p.x = (r - (info->n_row - 1) / 2.) * gap;
			obj->v[v_idx].p.y = (c - (info->n_col - 1) / 2.) * gap;
			obj->v[v_idx].p.z = info->height[r][c] / 10.;
			obj->v[v_idx].c = blend(&grad, 
				clipf(info->height[r][c], MIN_HEIGHT, MAX_HEIGHT)
				/ (MAX_HEIGHT - MIN_HEIGHT));
			c++;
		}
		r++;
	}
}

t_obj3d	*new_from_file(int fd)
{
	t_map_info	*info;
	t_obj3d		*obj;

	info = parse_file(fd);
	if (!info)
		return (NULL);
	obj = new_object3d((t_vec){0, 0, 0});
	obj->n_vertices = info->n_row * info->n_row;
	obj->n_edges = (info->n_row - 1) * info->n_col 
		+ (info->n_col - 1) * info->n_row;
	obj->v = safe_calloc(obj->n_vertices, sizeof(t_vertex));
	obj->e = safe_calloc(obj->n_edges, sizeof(t_edge));
	init_obj_vertices(obj, info);
	init_obj_edges(obj, info);
}
