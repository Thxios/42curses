/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:08:13 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/24 12:42:33 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object/object.h"
#include "utils/utils.h"

#include <stdio.h>

void	compute_camera_proj(t_obj3d *obj, t_camera *cam)
{
	int		idx;
	t_mat4	trans_proj;

	// matmul(obj->transform, cam->proj_mat, trans_proj);
	matmul(cam->proj_mat, obj->transform, trans_proj);
	// printf("trans proj mat:\n");
	// print_matrix(trans_proj);
	idx = 0;
	while (idx < obj->n_vertices)
	{
		proj_vec_to_vec4(trans_proj, obj->v[idx].p, obj->v[idx].scr_p);
		if ((cam->type == PERSPECTIVE) && (obj->v[idx].scr_p[3] > 1e-6))
		{
			obj->v[idx].scr_p[0] /= obj->v[idx].scr_p[3];
			obj->v[idx].scr_p[1] /= obj->v[idx].scr_p[3];
		}
		idx++;
	}
}

void	init_transform(t_mat4 out, t_vec p)
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

t_obj3d	*new_object3d(t_vec p)
{
	t_obj3d	*obj;

	obj = safe_malloc(sizeof(t_obj3d));
	obj->n_vertices = 0;
	obj->n_edges = 0;
	obj->v = NULL;
	obj->e = NULL;
	init_transform(obj->transform, p);
	return (obj);
}

void	translate(t_obj3d *obj, t_vec d)
{
	obj->transform[0][3] += d.x;
	obj->transform[1][3] += d.y;
	obj->transform[2][3] += d.z;
}
