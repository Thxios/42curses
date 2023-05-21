/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:48:52 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/02 12:57:33 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver/constants.h"
#include "solver/sort.h"
#include "solver/merge.h"
#include "solver/move.h"
#include "solver/manual.h"
#include "context/context.h"
#include "utils/deque.h"
#include "utils/comp.h"

int	check_a_back_sorted(int n, t_direction d)
{
	int		idx;
	t_node	*cur;

	cur = a()->tail;
	if (!cur)
		return (0);
	idx = 1;
	while (cur && (idx < n))
	{
		if ((d == ASC) != lt(cur->prv->val, cur->val))
			return (0);
		cur = cur->prv;
		idx++;
	}
	if (idx == n)
		return (1);
	else
		return (0);
}

void	sort_to_a(int n, t_direction d, t_position dest)
{
	int	n1;
	int	n2;
	int	n3;

	if (n <= 3)
	{
		sort_a_less_four(n, d, dest);
		return ;
	}
	else if (!check_a_back_sorted(n, d))
	{
		n1 = n / 3;
		n2 = ((2 * n) / 3) - n1;
		n3 = n - ((2 * n) / 3);
		sort_to_b(n1, d, FRONT);
		sort_to_b(n2, 1 - d, BACK);
		sort_to_a(n3, d, FRONT);
		merge_to_a(n1, n2, n3, d);
	}
	if (dest == FRONT)
		move_a_front(n);
}

void	sort_to_b(int n, t_direction d, t_position dest)
{
	int	n1;
	int	n2;
	int	n3;

	if (n <= 3)
		sort_b_less_four(n, d, dest);
	else
	{
		n1 = n / 3;
		n2 = ((2 * n) / 3) - n1;
		n3 = n - ((2 * n) / 3);
		sort_to_a(n1, d, FRONT);
		sort_to_b(n2, d, FRONT);
		sort_to_a(n3, 1 - d, BACK);
		merge_to_b(n1, n3, n2, d);
		if (dest == FRONT)
			move_b_front(n);
	}
}
