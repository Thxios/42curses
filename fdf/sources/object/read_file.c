/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:55:29 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/06 23:33:46 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object/read_file.h"
#include "utils/any_array.h"
#include "utils/ptr_array.h"
#include "utils/utils.h"
#include "libft.h"
#include "config.h"

#include <stdio.h>

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
		printf("read line %p, \"%s\": len %d\n", line, line, (int)ft_strlen(line));
		push_ptr_array(arr, line);
	}
	printf("readline done\n");
	if (arr->size == 0)
	{
		delete_ptr_array(arr, NULL);
		return (NULL);
	}
	map = safe_calloc(1, sizeof(t_map_info));
	map->n_row = arr->size;
	map->height = safe_calloc(map->n_row, sizeof(int *));
	map->height[0] = map_atoi_to_splited(arr->arr[0], &map->n_col);
	if (map->n_col == 0)
	{
		delete_ptr_array(arr, free);
		delete_map_info(map);
		return (NULL);
	}
	idx = 1;
	while (idx < arr->size) {
		map->height[idx] = map_atoi_to_splited(arr->arr[idx], &n_col);
		if (n_col != map->n_col)
		{
			delete_map_info(map);
			map = NULL;
			break;
		}
		idx++;
	}
	delete_ptr_array(arr, free);
	return (map);
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
		printf("row %d\n", r);
		c = 0;
		while (c < info->n_col)
		{
			if (r > 0)
			{
				obj->e[e_idx].st = rc_to_idx(r - 1, c, info->n_col);
				obj->e[e_idx].ed = rc_to_idx(r, c, info->n_col);
				// printf("%02d: E(st=(%d, %d), ed=(%d, %d))\n", e_idx, r-1, c, r, c);
				printf("%03d: H_E(st=", e_idx);
				print_vec(obj->v[obj->e[e_idx].st].p);
				printf("), ed=");
				print_vec(obj->v[obj->e[e_idx].ed].p);
				printf(")\n");
				e_idx++;
			}
			if (c > 0)
			{
				obj->e[e_idx].st = rc_to_idx(r, c - 1, info->n_col);
				obj->e[e_idx].ed = rc_to_idx(r, c, info->n_col);
				// printf("%02d: E(st=(%d, %d), ed=(%d, %d))\n", e_idx, r, c-1, r, c);
				printf("%03d: V_E(st=", e_idx);
				print_vec(obj->v[obj->e[e_idx].st].p);
				printf("), ed=");
				print_vec(obj->v[obj->e[e_idx].ed].p);
				printf(")\n");
				e_idx++;
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

	gap = clipf(20. / maxf(info->n_col, info->n_row), 0.1, 5);
	// offset_x = ((double)(info->n_row - 1) / 2) * gap;
	// offset_y = ((double)(info->n_col - 1) / 2) * gap;
	grad = make_grad(0x0000ff, 0xff0000);
	r = 0;
	while (r < info->n_row)
	{
		c = 0;
		while (c < info->n_col)
		{
			v_idx = rc_to_idx(r, c, info->n_col);
			obj->v[v_idx].p.x = (c - (info->n_col - 1.) / 2.) * gap;
			obj->v[v_idx].p.y = info->height[r][c] / 5.;
			obj->v[v_idx].p.z = -(r - (info->n_row - 1.) / 2.) * gap;
			obj->v[v_idx].c = blend(&grad,
				clipf(info->height[r][c], MIN_HEIGHT, MAX_HEIGHT)
				/ (MAX_HEIGHT - MIN_HEIGHT));
			c++;
			printf("%03d: V", v_idx);
			print_vec(obj->v[v_idx].p);
			printf("\n");
		}
		r++;
	}
}

t_obj3d	*new_from_file(int fd)
{
	t_map_info	*info;
	t_obj3d		*obj;

	info = parse_file(fd);
	printf("parse file done\n");
	if (!info)
		return (NULL);
	printf("info(nr=%d, nc=%d)\n", info->n_row, info->n_col);
	for (int r = 0; r < info->n_row; r++) {
		for (int c = 0; c < info->n_col; c++) {
			printf("%d ", info->height[r][c]);
		}
		printf("\n");
	}
	obj = new_object3d((t_vec){0, 0, 0});
	obj->n_vertices = info->n_row * info->n_col;
	obj->n_edges = (info->n_row - 1) * info->n_col
		+ (info->n_col - 1) * info->n_row;
	obj->v = safe_calloc(obj->n_vertices, sizeof(t_vertex));
	obj->e = safe_calloc(obj->n_edges, sizeof(t_edge));
	printf("obj alloc done\n");
	init_obj_vertices(obj, info);
	printf("vert init done\n");
	init_obj_edges(obj, info);
	printf("edge init done\n");
	delete_map_info(info);
	printf("delete map done\n");
	return (obj);
}
