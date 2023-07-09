/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_edge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:04:21 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 19:05:44 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/draw_obj.h"
#include "render/draw.h"

void	draw_edge_internal(t_image *img, t_vertex *a, t_vertex *b)
{
	draw_line(img, scr_to_pixel(a->scr_p), scr_to_pixel(b->scr_p), 0xffffff);
}
