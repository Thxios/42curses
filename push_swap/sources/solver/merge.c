/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:47:12 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/01 19:00:51 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver/merge.h"
#include "solver/merge_config.h"

static t_prior	find_top_priority(int l1, int r1, int l2, t_config *conf)
{
	long long	v_l1;
	long long	v_r1;
	long long	v_l2;

	v_l1 = conf->identity;
	if (l1)
		v_l1 = at(conf->q1, 0);
	v_r1 = conf->identity;
	if (r1)
		v_r1 = at(conf->q1, -1);
	v_l2 = conf->identity;
	if (l2)
		v_l2 = at(conf->q2, 0);
	if (conf->comp(v_l1, v_r1) && conf->comp(v_l1, v_l2))
		return (L1);
	else if (conf->comp(v_r1, v_l1) && conf->comp(v_r1, v_l2))
		return (R1);
	else
		return (L2);
}

static void	merge(int l1, int r1, int l2, t_config *conf)
{
	t_prior	best;

	while (l1 || r1 || l2)
	{
		best = find_top_priority(l1, r1, l2, conf);
		if (best == L1)
		{
			conf->rot1_fn();
			conf->push_fn();
			l1--;
		}
		else if (best == R1)
		{
			conf->push_fn();
			r1--;
		}
		else
		{
			conf->rot2_fn();
			l2--;
		}
	}
}

void	merge_to_a(int bl, int br, int ar, t_direction dir)
{
	if (dir == ASC)
		merge(bl, br, ar, get_config(A_ASC));
	else
		merge(bl, br, ar, get_config(A_DESC));
}

void	merge_to_b(int al, int ar, int br, t_direction dir)
{
	if (dir == ASC)
		merge(al, ar, br, get_config(B_ASC));
	else
		merge(al, ar, br, get_config(B_DESC));
}
