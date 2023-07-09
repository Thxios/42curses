/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:03:22 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 20:41:55 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "config.h"
#include "initialize.h"
#include "render/buffer.h"
#include "render/render.h"
#include "context/context.h"
#include "events/events.h"
#include "camera/camera.h"


void	initialize(t_upd *upd, t_obj3d *map_obj)
{
	ft_memset(upd, 0, sizeof(t_upd));
	init_camera();
	init_context();
	launch_window(WIDTH, HEIGHT, "fdf");
	initialize_mlx_hook(upd);
	upd->img = new_image(WIDTH, HEIGHT);
	upd->obj = map_obj;
	if (upd->obj)
	{
		translate_object(upd->obj, (t_vec){0, 0, 25});
		rotate_object(upd->obj, (t_vec){0, 1, 0}, -PI / 4);
		rotate_object(upd->obj, (t_vec){1, 0, 0}, -PI / 6);
	}
	render_frame(upd);
}

void	start_loop(void)
{
	mlx_loop(mlx());
}
