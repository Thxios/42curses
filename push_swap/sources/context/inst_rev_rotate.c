/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:32:29 by jimlee            #+#    #+#             */
/*   Updated: 2023/04/30 04:53:42 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context/context.h"

static void	rev_rotate(t_deque *q)
{
	if (q->size >= 2)
		push_back(q, pop_front(q));
}

void	rra(void)
{
	if (a()->size >= 2)
	{
		rev_rotate(a());
		if (logs()->size && logs()->arr[logs()->size - 1] == RA)
			pop_array(logs());
		else if (logs()->size && logs()->arr[logs()->size - 1] == RRB)
		{
			pop_array(logs());
			push_array(logs(), RRR);
		}
		else
			push_array(get_context()->log, RRA);
	}
}

void	rrb(void)
{
	if (b()->size >= 2)
	{
		rev_rotate(b());
		if (logs()->size && logs()->arr[logs()->size - 1] == RB)
			pop_array(logs());
		else if (logs()->size && logs()->arr[logs()->size - 1] == RRA)
		{
			pop_array(logs());
			push_array(logs(), RRR);
		}
		else
			push_array(get_context()->log, RRB);
	}
}

void	rrr(void)
{
	rev_rotate(a());
	rev_rotate(b());
	if (logs()->size && logs()->arr[logs()->size - 1] == RR)
		pop_array(logs());
	else
		push_array(get_context()->log, RRR);
}
