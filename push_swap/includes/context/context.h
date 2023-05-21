/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:08:40 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/02 12:39:54 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

# include "utils/array.h"
# include "utils/deque.h"

typedef struct s_state
{
	t_deque	*a;
	t_deque	*b;
	t_array	*log;
}			t_state;

typedef enum e_inst
{
	NONE = 0,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_inst;

t_state		*get_context(void);
t_deque		*a(void);
t_deque		*b(void);
t_array		*logs(void);

void		init_context(t_array *arr);
void		delete_context(void);

void		sa(void);
void		sb(void);
void		ss(void);
void		pa(void);
void		pb(void);
void		ra(void);
void		rb(void);
void		rr(void);
void		rra(void);
void		rrb(void);
void		rrr(void);

const char	*get_instruction_name(t_inst inst);
t_inst		get_instruction_by_name(const char *s);
void		(*get_instruction_function(t_inst inst))(void);

#endif
