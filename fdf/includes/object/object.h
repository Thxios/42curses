/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:09:45 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/28 13:15:15 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

#include "utils/matrix.h"
#include "utils/vector.h"
#include "camera/camera.h"

typedef struct s_edge
{
	int	st;
	int	ed;
}		t_edge;

typedef struct s_vertex
{
	t_vec	p;
	t_vec4	scr_p;
}			t_vertex;

typedef struct s_obj3d
{
	int			n_vertices;
	int			n_edges;
	t_vertex	*v;
	t_edge		*e;
	t_mat4		transform;
}				t_obj3d;

void	compute_camera_proj(t_obj3d *obj, t_camera *cam);
t_obj3d	*new_object3d(t_vec p);
void	translate(t_obj3d *obj, t_vec d);

#endif
