/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:38:11 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 18:51:55 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "config.h"
#include "utils/utils.h"
#include "object/object.h"
#include "object/map_info.h"

int	validate_map_file_extension(char *path)
{
	char	*trimmed;
	int		len;
	int		valid;

	trimmed = ft_strtrim(path, " ");
	len = ft_strlen(trimmed);
	valid = (len > 4) && (ft_strcmp(&trimmed[len - 4], ".fdf") == 0);
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
				obj->e[e_idx].ed = rc_to_idx(r, c, info->n_col);
				e_idx++;
			}
			if (c > 0)
			{
				obj->e[e_idx].st = rc_to_idx(r, c - 1, info->n_col);
				obj->e[e_idx].ed = rc_to_idx(r, c, info->n_col);
				e_idx++;
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

	gap = clipf(30. / maxf(info->n_col, info->n_row), 0.1, 5);
	// printf("gap %.3f\n", gap);
	// offset_x = ((double)(info->n_row - 1) / 2) * gap;
	// offset_y = ((double)(info->n_col - 1) / 2) * gap;
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
			obj->v[v_idx].c = get_color_heatmap(
				((double)info->height[r][c] - MIN_HEIGHT) / (MAX_HEIGHT - MIN_HEIGHT));
			c++;
			// printf("%03d: V", v_idx);
			// print_vec(obj->v[v_idx].p);
			// printf(", c=%.6x\n", obj->v[v_idx].c);
		}
		r++;
	}
}

t_obj3d	*read_object_from_file(int fd)
{
	t_map_info	*info;
	t_obj3d		*obj;

	info = parse_file_to_map_info(fd);
	// printf("parse file done\n");
	if (!info)
		return (NULL);
	// printf("info(nr=%d, nc=%d)\n", info->n_row, info->n_col);
	// for (int r = 0; r < info->n_row; r++) {
	// 	for (int c = 0; c < info->n_col; c++) {
	// 		printf("%d ", info->height[r][c]);
	// 	}
	// 	printf("\n");
	// }
	obj = new_object3d((t_vec){0, 0, 0});
	obj->n_vertices = info->n_row * info->n_col;
	obj->n_edges = (info->n_row - 1) * info->n_col
		+ (info->n_col - 1) * info->n_row;
	obj->v = safe_calloc(obj->n_vertices, sizeof(t_vertex));
	obj->e = safe_calloc(obj->n_edges, sizeof(t_edge));
	// printf("obj alloc done\n");
	init_obj_vertices(obj, info);
	// printf("vert init done\n");
	init_obj_edges(obj, info);
	// printf("edge init done\n");
	delete_map_info(info);
	// printf("delete map done\n");
	return (obj);
}
