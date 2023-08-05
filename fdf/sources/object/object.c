/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:08:13 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 16:25:38 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object/object.h"
#include "utils/utils.h"
#include "utils/quaternion.h"

#include <stdio.h>
#include <stdlib.h>

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
