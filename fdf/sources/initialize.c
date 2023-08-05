/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:03:22 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 19:33:39 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "config.h"
#include "initialize.h"
#include "events/events.h"
#include "camera/camera.h"


void	initialize(t_upd *upd)
{
	ft_memset(upd, 0, sizeof(t_upd));
	init_camera();
	init_context();
	launch_window(WIDTH, HEIGHT, "fdf");
	initialize_mlx_hook(upd);
}

void	start_loop(void)
{
	mlx_loop(mlx());
}
