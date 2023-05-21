/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:58:10 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/01 19:22:57 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver/constants.h"
#include "solver/move.h"
#include "context/context.h"
#include "utils/comp.h"

static void	sort_a_three_three(int (*comp)(long long, long long))
{
	if (comp(at(a(), -1), at(a(), -3)) && comp(at(a(), -1), at(a(), -2)))
		ra();
	else if (comp(at(a(), -2), at(a(), -1)) && comp(at(a(), -2), at(a(), -3)))
		rra();
	if (comp(at(a(), -1), at(a(), -2)))
		sa();
}

static void	sort_a_three_top(int (*comp)(long long, long long))
{
	if (a()->size == 3)
	{
		sort_a_three_three(comp);
		return ;
	}
	if (comp(at(a(), -1), at(a(), -3)) && comp(at(a(), -1), at(a(), -2)))
		sa();
	if (comp(at(a(), -2), at(a(), -3)) && comp(at(a(), -2), at(a(), -1)))
	{
		pb();
		sa();
		pa();
	}
	if (comp(at(a(), -1), at(a(), -2)))
		sa();
}

static void	sub_case_a_bot(int (*comp)(long long, long long))
{
	pb();
	sa();
	ra();
	if (comp(at(a(), -1), at(b(), -1)))
	{
		ra();
		pa();
	}
	else
	{
		pa();
		ra();
	}
}

static void	sort_a_three_bot(int (*comp)(long long, long long))
{
	if (comp(at(a(), -3), at(a(), -2)) && comp(at(a(), -3), at(a(), -1)))
		sub_case_a_bot(comp);
	else
	{
		if (comp(at(a(), -2), at(a(), -1)))
			sa();
		ra();
		if (comp(at(a(), -2), at(a(), -1)))
			sa();
		ra();
	}
	ra();
}

void	sort_a_three(t_direction d, t_position dest)
{
	if (dest == FRONT && a()->size != 3)
	{
		if (d == ASC)
			sort_a_three_bot(gt);
		else
			sort_a_three_bot(lt);
	}
	else
	{
		if (d == ASC)
			sort_a_three_top(lt);
		else
			sort_a_three_top(gt);
	}
}
