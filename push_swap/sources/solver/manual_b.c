/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:23:08 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/01 19:23:09 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver/constants.h"
#include "solver/move.h"
#include "context/context.h"
#include "utils/comp.h"

void	sort_b_two(t_direction d, t_position dest)
{
	pb();
	if (dest == FRONT)
	{
		if ((d == ASC) != lt(at(a(), -1), at(b(), -1)))
		{
			pb();
			move_b_front(2);
		}
		else
		{
			move_b_front(1);
			pb();
			move_b_front(1);
		}
	}
	else
	{
		pb();
		if ((d == ASC) != lt(at(b(), -2), at(b(), -1)))
			sb();
	}
}

static void	sort_b_three_top(int (*comp)(long long, long long))
{
	if (comp(at(a(), -1), at(a(), -2)) && comp(at(a(), -1), at(a(), -3)))
		sa();
	pb();
	if (comp(at(a(), -1), at(a(), -2)))
		sa();
	pb();
	if (comp(at(b(), -2), at(b(), -1)))
		sb();
	pb();
}

static void	sub_case_b_bot(int (*comp)(long long, long long))
{
	if (comp(at(a(), -1), at(b(), -1)))
	{
		rb();
		pb();
	}
	else
	{
		pb();
		rb();
	}
	if (comp(at(a(), -1), at(b(), -1)))
	{
		rb();
		pb();
	}
	else
	{
		pb();
		rb();
	}
}

static void	sort_b_three_bot(int (*comp)(long long, long long))
{
	if (comp(at(a(), -2), at(a(), -1)) && comp(at(a(), -1), at(a(), -3)))
		sa();
	pb();
	if (comp(at(b(), -1), at(a(), -1)) && comp(at(a(), -1), at(a(), -2)))
	{
		pb();
		pb();
		rb();
		rb();
	}
	else
		sub_case_b_bot(comp);
	rb();
}

void	sort_b_three(t_direction d, t_position dest)
{
	if (dest == FRONT && b()->size != 0)
	{
		if (d == ASC)
			sort_b_three_bot(lt);
		else
			sort_b_three_bot(gt);
	}
	else
	{
		if (d == ASC)
			sort_b_three_top(gt);
		else
			sort_b_three_top(lt);
	}
}
