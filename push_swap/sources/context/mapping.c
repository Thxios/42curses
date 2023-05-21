/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 03:39:04 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/02 15:30:32 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context/context.h"
#include "libft/libft.h"

void	none_func(void)
{
}

const char	*get_instruction_name(t_inst inst)
{
	static const char	*names[12] = {
		"none", "sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"
	};

	if (((int)inst < 0) || ((int)inst >= 12))
		return ("none");
	return (names[(int)inst]);
}

t_inst	get_instruction_by_name(const char *s)
{
	if (ft_strcmp(s, "sa") == 0)
		return (SA);
	if (ft_strcmp(s, "sb") == 0)
		return (SB);
	if (ft_strcmp(s, "ss") == 0)
		return (SS);
	if (ft_strcmp(s, "pa") == 0)
		return (PA);
	if (ft_strcmp(s, "pb") == 0)
		return (PB);
	if (ft_strcmp(s, "ra") == 0)
		return (RA);
	if (ft_strcmp(s, "rb") == 0)
		return (RB);
	if (ft_strcmp(s, "rr") == 0)
		return (RR);
	if (ft_strcmp(s, "rra") == 0)
		return (RRA);
	if (ft_strcmp(s, "rrb") == 0)
		return (RRB);
	if (ft_strcmp(s, "rrr") == 0)
		return (RRR);
	return (NONE);
}

void	(*get_instruction_function(t_inst inst))(void)
{
	if (inst == SA)
		return (sa);
	if (inst == SB)
		return (sb);
	if (inst == SS)
		return (ss);
	if (inst == PA)
		return (pa);
	if (inst == PB)
		return (pb);
	if (inst == RA)
		return (ra);
	if (inst == RB)
		return (rb);
	if (inst == RR)
		return (rr);
	if (inst == RRA)
		return (rrr);
	if (inst == RRB)
		return (rrb);
	if (inst == RRR)
		return (rrr);
	return (none_func);
}
