/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:30:12 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/15 00:50:39 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context/context.h"
#include "mlx.h"

void	init_context(void)
{
	t_context	*context;

	context = ctx();
	context->mlx = mlx_init();
}

void	launch_window(int width, int height, char *title)
{
	t_context	*context;

	context = ctx();
	context->window = mlx_new_window(context->mlx, width, height, title);
}
