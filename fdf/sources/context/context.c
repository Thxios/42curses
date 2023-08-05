/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:22:49 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 16:49:09 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "context/context.h"

t_context	*ctx(void)
{
	static t_context	context;

	return (&context);
}

void	*mlx(void)
{
	return	(ctx()->mlx);
}

void	*window(void)
{
	return (ctx()->window);
}

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

