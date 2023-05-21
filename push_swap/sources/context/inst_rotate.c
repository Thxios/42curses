/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:27:47 by jimlee            #+#    #+#             */
/*   Updated: 2023/04/30 04:54:47 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context/context.h"

static void	rotate(t_deque *q)
{
	if (q->size >= 2)
		push_front(q, pop_back(q));
}

void	ra(void)
{
	if (a()->size >= 2)
	{
		rotate(a());
		if (logs()->size && logs()->arr[logs()->size - 1] == RRA)
			pop_array(logs());
		else if (logs()->size && logs()->arr[logs()->size - 1] == RB)
		{
			pop_array(logs());
			push_array(logs(), RR);
		}
		else
			push_array(get_context()->log, RA);
	}
}

void	rb(void)
{
	if (b()->size >= 2)
	{
		rotate(b());
		if (logs()->size && logs()->arr[logs()->size - 1] == RRB)
			pop_array(logs());
		else if (logs()->size && logs()->arr[logs()->size - 1] == RA)
		{
			pop_array(logs());
			push_array(logs(), RR);
		}
		else
			push_array(get_context()->log, RB);
	}
}

void	rr(void)
{
	rotate(a());
	rotate(b());
	if (logs()->size && logs()->arr[logs()->size - 1] == RRR)
		pop_array(logs());
	else
		push_array(get_context()->log, RR);
}
