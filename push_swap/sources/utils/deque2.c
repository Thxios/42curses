/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:58:59 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/01 14:32:21 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/deque.h"
#include "utils/safe_malloc.h"

int	at(t_deque *q, int idx)
{
	t_node	*cur;

	if (idx >= 0)
	{
		cur = q->head;
		while (idx > 0)
		{
			cur = cur->nxt;
			idx--;
		}
	}
	else
	{
		cur = q->tail;
		while (idx < -1)
		{
			cur = cur->prv;
			idx++;
		}
	}
	return (cur->val);
}

t_deque	*new_deque(void)
{
	t_deque	*ret;

	ret = safe_malloc(sizeof(t_deque));
	ret->head = NULL;
	ret->tail = NULL;
	ret->size = 0;
	return (ret);
}

void	delete_deque(t_deque *q)
{
	t_node	*cur;
	t_node	*temp;

	cur = q->head;
	while (cur)
	{
		temp = cur;
		cur = cur->nxt;
		free(temp);
	}
	free(q);
}
