/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:38:27 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 02:49:59 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/render.h"
#include "context/context.h"
#include "utils/point.h"
#include "mlx.h"
#include "render/draw.h"
#include "update/frame.h"
#include "render/draw_obj.h"

int	render_frame(t_upd *var)
{
	fill(var->img, 0);
	// set_pixel(var->img, 100, 100, rgb2color(255, 0, 0));
	// draw_line_grad(var->img, (t_pos){100, 100}, (t_pos){300, 200}, make_grad(0xff0000, 0xff));
	// draw_line_grad(var->img, (t_pos){500, 500}, (t_pos){300, 200}, make_grad(0xff0000, 0xff));
	// draw_line_grad(var->img, (t_pos){100, 100}, (t_pos){100, 300}, make_grad(0xff0000, 0xff));
	// draw_line_grad(var->img, (t_pos){300, 200}, (t_pos){100, 300}, make_grad(0xff0000, 0xff));
	// draw_line_grad(var->img, (t_pos){600, 200}, (t_pos){500, 700}, make_grad(0xff0000, 0xff));
	// draw_line_grad(var->img, (t_pos){600, 200}, (t_pos){500, 700}, make_grad(0xff0000, 0xffff));
	if (var->obj)
		draw_object(var->img, var->obj);
	mlx_put_image_to_window(mlx(), window(), var->img->image, 0, 0);
	return (0);
}
