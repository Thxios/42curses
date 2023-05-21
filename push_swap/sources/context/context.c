/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:01:02 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/09 16:58:40 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context/context.h"

t_state	*get_context(void)
{
	static t_state	context;

	return (&context);
}

t_deque	*a(void)
{
	return (get_context()->a);
}

t_deque	*b(void)
{
	return (get_context()->b);
}

t_array	*logs(void)
{
	return (get_context()->log);
}
