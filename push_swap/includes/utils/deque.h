/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 04:26:05 by thxios            #+#    #+#             */
/*   Updated: 2023/05/01 14:31:08 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

typedef struct s_node
{
	int				val;
	struct s_node	*prv;
	struct s_node	*nxt;
}					t_node;

typedef struct s_deque
{
	int		size;
	t_node	*head;
	t_node	*tail;
}			t_deque;

t_deque	*new_deque(void);
void	delete_deque(t_deque *q);

void	push_back(t_deque *q, int val);
void	push_front(t_deque *q, int val);
int		pop_back(t_deque *q);
int		pop_front(t_deque *q);
int		at(t_deque *q, int idx);

#endif
