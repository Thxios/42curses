/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:34:05 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 20:31:03 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "render/draw_obj.h"
#include "camera/camera.h"

#include <stdio.h>

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

void	draw_edge(t_image *img, t_vertex *a, t_vertex *b)
{
	if ((a->scr_p[2] < -1) || (b->scr_p[2] < -1))
		return ;
	if (is_outside_camera(a->scr_p) && is_outside_camera(b->scr_p))
		return ;
	draw_edge_internal(img, a, b);
	// draw_line(img, scr_to_pixel(a->scr_p), scr_to_pixel(b->scr_p), 0xffffff);
	// draw_line_grad(img, scr_to_pixel(a->scr_p), scr_to_pixel(b->scr_p), make_grad(a->c, b->c));
}

void	draw_object_to_img(t_image *img, t_obj3d *obj)
{
	// printf("draw object %p\n", obj);
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
