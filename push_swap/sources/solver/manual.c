/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:06:00 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/01 19:38:41 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver/constants.h"
#include "solver/manual_hdr.h"
#include "solver/move.h"
#include "context/context.h"
#include "utils/comp.h"

void	sort_a_less_four(int n, t_direction d, t_position dest)
{
	if (n <= 2)
	{
		if (n == 2 && ((d == ASC) != lt(at(a(), -2), at(a(), -1))))
			sa();
		if (dest == FRONT)
			move_a_front(n);
	}
	else if (n == 3)
		sort_a_three(d, dest);
}

void	sort_b_less_four(int n, t_direction d, t_position dest)
{
	if (n == 1)
	{
		pb();
		if (dest == FRONT)
			move_b_front(1);
	}
	else if (n == 2)
		sort_b_two(d, dest);
	else if (n == 3)
		sort_b_three(d, dest);
}
