/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:38:27 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/10 10:14:25 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/render.h"
#include "context/context.h"
#include "utils/point.h"
#include "mlx.h"
#include "render/draw.h"
#include "update.h"
#include "render/draw_obj.h"

void	render_frame(t_upd *upd)
{
	fill_image(upd->img, 0);
	if (upd->obj)
		draw_object_to_img(upd->img, upd->obj);
	mlx_put_image_to_window(mlx(), window(), upd->img->image, 0, 0);
}
