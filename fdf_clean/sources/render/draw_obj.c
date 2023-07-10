/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:34:05 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/10 10:16:45 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "render/draw_obj.h"
#include "camera/camera.h"
#include "utils/point.h"

int	is_outside_camera(t_vec4 scr_p)
{
	if (scr_p[0] < -1 || scr_p[0] > 1)
		return (1);
	if (scr_p[1] < -1 || scr_p[1] > 1)
		return (1);
	if (scr_p[2] < -1 || scr_p[2] > 1)
		return (1);
	return (0);
}

t_pos	scr_to_pixel(t_vec4 scr_p)
{
	return ((t_pos){
		0.5 * (scr_p[0] + 1) * WIDTH,
		0.5 * (-scr_p[1] + 1) * HEIGHT
	});
}

void	compute_camera_proj(t_obj3d *obj, t_camera *cam)
{
	int				idx;
	static t_mat4	total;

	matmul(cam->proj_mat, obj->transform, total);
	idx = 0;
	while (idx < obj->n_vertices)
	{
		proj_vec_to_vec4(total, obj->v[idx].p, obj->v[idx].scr_p);
		if ((cam->type == PERSPECTIVE) && (obj->v[idx].scr_p[3] > 1e-6))
		{
			obj->v[idx].scr_p[0] /= obj->v[idx].scr_p[3];
			obj->v[idx].scr_p[1] /= obj->v[idx].scr_p[3];
		}
		idx++;
	}
}

void	draw_edge(t_image *img, t_vertex *a, t_vertex *b)
{
	if ((a->scr_p[2] < -1) || (b->scr_p[2] < -1))
		return ;
	if (is_outside_camera(a->scr_p) && is_outside_camera(b->scr_p))
		return ;
	draw_edge_internal(img, a, b);
}

void	draw_object_to_img(t_image *img, t_obj3d *obj)
{
	int	idx;
	int	a;
	int	b;

	compute_camera_proj(obj, camera());
	idx = 0;
	while (idx < obj->n_edges)
	{
		a = obj->e[idx].st;
		b = obj->e[idx].ed;
		draw_edge(img, &obj->v[a], &obj->v[b]);
		idx++;
	}
}
