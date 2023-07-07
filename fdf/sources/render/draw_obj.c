/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:34:05 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/07 17:36:22 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/draw_obj.h"
#include "render/draw.h"
#include "utils/point.h"
#include "config.h"

#include <stdio.h>

int	is_outside_camera(t_vec4 scr_p)
{
	if (scr_p[0] < -1 || scr_p[0] > 1)
		return (1);
	if (scr_p[1] < -1 || scr_p[1] > 1)
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

void show(t_vec4 p) {
	printf("(%.2f, %.2f, %.2f, %.2f)", p[0], p[1], p[2], p[3]);
}

void	draw_edge(t_image *img, t_vertex *a, t_vertex *b)
{
	// printf("draw: a=");
	// show(a->scr_p);
	// printf(", b=");
	// show(b->scr_p);
	// printf("\n");
	if ((a->scr_p[2] < -1) || (b->scr_p[2] < -1))
		return ;
	if (is_outside_camera(a->scr_p) && is_outside_camera(b->scr_p))
		return ;

	// draw_line(img, scr_to_pixel(a->scr_p), scr_to_pixel(b->scr_p), 0xffffff);
	draw_line_grad(img, scr_to_pixel(a->scr_p), scr_to_pixel(b->scr_p), make_grad(a->c, b->c));
}

void	draw_object(t_image *img, t_obj3d *obj)
{
	// printf("draw object %p\n", obj);
	int	idx;
	int	a;
	int	b;

	idx = 0;
	while (idx < obj->n_edges)
	{
		a = obj->e[idx].st;
		b = obj->e[idx].ed;
		draw_edge(img, &obj->v[a], &obj->v[b]);
		idx++;
	}
}
