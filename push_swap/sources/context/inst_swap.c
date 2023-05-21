/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:12:54 by jimlee            #+#    #+#             */
/*   Updated: 2023/04/30 04:55:52 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context/context.h"

static void	swap_top(t_deque *q)
{
	int	v1;
	int	v2;

	if (q->size >= 2)
	{
		v1 = pop_back(q);
		v2 = pop_back(q);
		push_back(q, v1);
		push_back(q, v2);
	}
}

void	sa(void)
{
	if (a()->size >= 2)
	{
		swap_top(a());
		if (logs()->size && logs()->arr[logs()->size - 1] == SA)
			pop_array(logs());
		else if (logs()->size && logs()->arr[logs()->size - 1] == SB)
		{
			pop_array(logs());
			push_array(logs(), SS);
		}
		else
			push_array(get_context()->log, SA);
	}
}

void	sb(void)
{
	if (b()->size >= 2)
	{
		swap_top(b());
		if (logs()->size && logs()->arr[logs()->size - 1] == SB)
			pop_array(logs());
		else if (logs()->size && logs()->arr[logs()->size - 1] == SA)
		{
			pop_array(logs());
			push_array(logs(), SS);
		}
		else
			push_array(get_context()->log, SB);
	}
}

void	ss(void)
{
	swap_top(a());
	swap_top(b());
	if (logs()->size && logs()->arr[logs()->size - 1] == SS)
		pop_array(logs());
	else
		push_array(get_context()->log, SS);
}
