/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:22:49 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/14 20:27:05 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
