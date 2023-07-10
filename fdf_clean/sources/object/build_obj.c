/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:38:11 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/10 10:43:22 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "config.h"
#include "object/object.h"
#include "object/map_info.h"
#include "utils/utils.h"

int	validate_map_file_extension(char *path)
{
	char	*trimmed;
	int		len;
	int		valid;

	trimmed = ft_strtrim(path, " ");
	len = ft_strlen(trimmed);
	valid = ((len > 4) && (ft_strcmp(&trimmed[len - 4], ".fdf") == 0));
	free(trimmed);
	return (valid);
}

int	rc_to_idx(int row, int col, int n_col)
{
	return (row * n_col + col);
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
				obj->e[e_idx].st = rc_to_idx(r - 1, c, info->n_col);
				obj->e[e_idx++].ed = rc_to_idx(r, c, info->n_col);
			}
			if (c > 0)
			{
				obj->e[e_idx].st = rc_to_idx(r, c - 1, info->n_col);
				obj->e[e_idx++].ed = rc_to_idx(r, c, info->n_col);
			}
			c++;
		}
		r++;
	}
}

void	init_obj_vertices(t_obj3d *obj, t_map_info *info)
{
	int		r;
	int		c;
	int		v_idx;
	double	gap;

	gap = clipf(MAP_OBJ_SIZE / maxf(info->n_col, info->n_row), 0.25, 5);
	r = 0;
	while (r < info->n_row)
	{
		c = 0;
		while (c < info->n_col)
		{
			v_idx = rc_to_idx(r, c, info->n_col);
			obj->v[v_idx].p.x = (c - (info->n_col - 1.) / 2.) * gap;
			obj->v[v_idx].p.y = info->height[r][c] * gap - 5.;
			obj->v[v_idx].p.z = -(r - (info->n_row - 1.) / 2.) * gap;
			obj->v[v_idx].c = get_color_heatmap(
					((double)info->height[r][c] - MIN_HEIGHT)
					/ (MAX_HEIGHT - MIN_HEIGHT));
			c++;
		}
		r++;
	}
}

t_obj3d	*read_object_from_file(int fd)
{
	t_map_info	*info;
	t_obj3d		*obj;

	info = parse_file_to_map_info(fd);
	if (!info)
		return (NULL);
	obj = new_object3d((t_vec){0, 0, 0});
	obj->n_vertices = info->n_row * info->n_col;
	obj->n_edges = (info->n_row - 1) * info->n_col
		+ (info->n_col - 1) * info->n_row;
	obj->v = safe_calloc(obj->n_vertices, sizeof(t_vertex));
	obj->e = safe_calloc(obj->n_edges, sizeof(t_edge));
	init_obj_vertices(obj, info);
	init_obj_edges(obj, info);
	delete_map_info(info);
	return (obj);
}
