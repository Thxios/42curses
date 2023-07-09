/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:55:52 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 19:08:19 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "update.h"
#include "context/context.h"

#include <stdio.h>

int	quit_event(t_upd *upd)
{
	printf("quit event\n");
	if (upd->img)
		mlx_destroy_image(mlx(), upd->img->image);
	mlx_destroy_window(mlx(), window());
	exit(0);
	return (0);
}
