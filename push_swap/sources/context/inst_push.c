/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:23:54 by jimlee            #+#    #+#             */
/*   Updated: 2023/04/30 04:51:58 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context/context.h"

static void	push(t_deque *from, t_deque *to)
{
	if (from->size >= 1)
		push_back(to, pop_back(from));
}

void	pa(void)
{
	if (b()->size >= 1)
	{
		push(b(), a());
		if (logs()->size && logs()->arr[logs()->size - 1] == PB)
			pop_array(logs());
		else
			push_array(get_context()->log, PA);
	}
}

void	pb(void)
{
	if (a()->size >= 1)
	{
		push(a(), b());
		if (logs()->size && logs()->arr[logs()->size - 1] == PA)
			pop_array(logs());
		else
			push_array(get_context()->log, PB);
	}
}
