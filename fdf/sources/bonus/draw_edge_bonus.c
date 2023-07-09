/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_edge_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:04:21 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 19:06:29 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/draw_obj.h"
#include "render/draw.h"

void	draw_edge_internal(t_image *img, t_vertex *a, t_vertex *b)
{
	draw_line_grad(img,
		scr_to_pixel(a->scr_p), scr_to_pixel(b->scr_p), 
		make_grad(a->c, b->c));
}
