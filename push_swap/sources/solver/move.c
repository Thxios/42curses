/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:24:25 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/01 19:02:07 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/deque.h"
#include "context/context.h"

static void	move_to_front(t_deque *q, int n, void (*r_fn)(), void (*rr_fn)())
{
	if (n != q->size)
	{
		if (n > q->size - n)
		{
			while (n < q->size)
			{
				rr_fn();
				n++;
			}
		}
		else
		{
			while (n)
			{
				r_fn();
				n--;
			}
		}
	}
}

void	move_a_front(int n)
{
	move_to_front(a(), n, ra, rra);
}

void	move_b_front(int n)
{
	move_to_front(b(), n, rb, rrb);
}
