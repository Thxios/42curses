/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:08:13 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/08 14:30:22 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object/object.h"
#include "utils/utils.h"
#include "utils/quaternion.h"

#include <stdio.h>
#include <stdlib.h>

void	compute_camera_proj(t_obj3d *obj, t_camera *cam)
{
	int		idx;
	static t_mat4	total;
	// t_mat4	trans_proj;
	// t_vec	rel_p;

	// matmul(obj->rotation, cam->proj_mat, trans_proj);
	// matmul(cam->proj_mat, obj->translation, tmp);
	// matmul(tmp, obj->rotation, total);
	// matmul(obj->translation, obj->transform, tmp);
	matmul(cam->proj_mat, obj->transform, total);
	// printf("\ntransform:\n");
	// print_matrix(obj->transform);
	// printf("\ncam:\n");
	// print_matrix(cam->proj_mat);
	// printf("\ntotal:\n");
	// print_matrix(total);
	// exit(0);
	// matmul(cam->proj_mat, obj->transform, trans_proj);
	// printf("trans proj mat:\n");
	// print_matrix(trans_proj);
	idx = 0;
	while (idx < obj->n_vertices)
	{
		// rel_p = (t_vec){obj->v[idx].p.x + obj->center.x,
		//  obj->v[idx].p.y + obj->center.y,
		//  obj->v[idx].p.z + obj->center.z};
		// proj_vec_to_vec4(trans_proj, obj->v[idx].p, obj->v[idx].scr_p);
		// proj_vec_to_vec(obj->rotation, obj->v[idx].p, &rel_p);
		// rel_p.x += obj->center.x;
		// rel_p.y += obj->center.y;
		// rel_p.z += obj->center.z;
		// proj_vec_to_vec4(trans_proj, obj->v[idx].p, obj->v[idx].scr_p);
		// proj_vec_to_vec4(cam->proj_mat, rel_p, obj->v[idx].scr_p);
		proj_vec_to_vec4(total, obj->v[idx].p, obj->v[idx].scr_p);
		if ((cam->type == PERSPECTIVE) && (obj->v[idx].scr_p[3] > 1e-6))
		{
			obj->v[idx].scr_p[0] /= obj->v[idx].scr_p[3];
			obj->v[idx].scr_p[1] /= obj->v[idx].scr_p[3];
		}
		idx++;
	}
}

void	init_transform_matrix(t_mat4 out, t_vec p)
{
	out[0][0] = 1;
	out[0][1] = 0;
	out[0][2] = 0;
	out[0][3] = p.x;
	out[1][0] = 0;
	out[1][1] = 1;
	out[1][2] = 0;
	out[1][3] = p.y;
	out[2][0] = 0;
	out[2][1] = 0;
	out[2][2] = 1;
	out[2][3] = p.z;
	out[3][0] = 0;
	out[3][1] = 0;
	out[3][2] = 0;
	out[3][3] = 1;
}

t_obj3d	*new_object3d(t_vec center)
{
	t_obj3d	*obj;

	obj = safe_malloc(sizeof(t_obj3d));
	obj->n_vertices = 0;
	obj->n_edges = 0;
	obj->v = NULL;
	obj->e = NULL;
	init_transform_matrix(obj->transform, center);
	return (obj);
}

void	translate_object(t_obj3d *obj, t_vec d)
{
	obj->transform[0][3] += d.x;
	obj->transform[1][3] += d.y;
	obj->transform[2][3] += d.z;
}

void	rotate_object(t_obj3d *obj, t_vec axis, double angle)
{
	static t_mat4	rot_matrix;
	static t_mat4	tmp;

	get_rotation_matrix(angle, axis, rot_matrix);
	// matmul(obj->transform, rot_matrix, tmp);
	matmul_3d(rot_matrix, obj->transform, tmp);
	copy_matrix_3d(obj->transform, tmp);
	// matmul_inplace(obj->transform, rot_matrix);
}
