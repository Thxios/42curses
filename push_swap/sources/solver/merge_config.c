/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:12:02 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/01 19:00:04 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver/merge_config.h"
#include "context/context.h"
#include "utils/comp.h"

t_config	*get_config(t_merge_type merge_type)
{
	static t_config	configs[4];

	return (&configs[(int)merge_type]);
}

static void	init_a_config(t_config *conf)
{
	conf->q1 = b();
	conf->q2 = a();
	conf->push_fn = pa;
	conf->rot1_fn = rrb;
	conf->rot2_fn = rra;
}

static void	init_b_config(t_config *conf)
{
	conf->q1 = a();
	conf->q2 = b();
	conf->push_fn = pb;
	conf->rot1_fn = rra;
	conf->rot2_fn = rrb;
}

void	init_config(void)
{
	init_a_config(get_config(A_ASC));
	init_a_config(get_config(A_DESC));
	get_config(A_ASC)->comp = lt;
	get_config(A_ASC)->identity = MAX;
	get_config(A_DESC)->comp = gt;
	get_config(A_DESC)->identity = MIN;
	init_b_config(get_config(B_ASC));
	init_b_config(get_config(B_DESC));
	get_config(B_ASC)->comp = lt;
	get_config(B_ASC)->identity = MAX;
	get_config(B_DESC)->comp = gt;
	get_config(B_DESC)->identity = MIN;
}
