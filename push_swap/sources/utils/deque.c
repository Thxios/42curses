/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:45:08 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/01 14:31:47 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/deque.h"
#include "utils/safe_malloc.h"

static t_node	*new_node(int val)
{
	t_node	*ret;

	ret = safe_malloc(sizeof(t_node));
	ret->prv = NULL;
	ret->nxt = NULL;
	ret->val = val;
	return (ret);
}

void	push_back(t_deque *q, int val)
{
	if (!q->head)
	{
		q->head = new_node(val);
		q->tail = q->head;
	}
	else
	{
		q->tail->nxt = new_node(val);
		q->tail->nxt->prv = q->tail;
		q->tail = q->tail->nxt;
	}
	q->size++;
}

void	push_front(t_deque *q, int val)
{
	if (!q->head)
	{
		q->head = new_node(val);
		q->tail = q->head;
	}
	else
	{
		q->head->prv = new_node(val);
		q->head->prv->nxt = q->head;
		q->head = q->head->prv;
	}
	q->size++;
}

int	pop_back(t_deque *q)
{
	t_node	*temp;
	int		ret;

	ret = q->tail->val;
	temp = q->tail;
	q->tail = q->tail->prv;
	if (q->tail)
		q->tail->nxt = NULL;
	else
		q->head = NULL;
	q->size--;
	free(temp);
	return (ret);
}

int	pop_front(t_deque *q)
{
	t_node	*temp;
	int		ret;

	ret = q->head->val;
	temp = q->head;
	q->head = q->head->nxt;
	if (q->head)
		q->head->prv = NULL;
	else
		q->tail = NULL;
	q->size--;
	free(temp);
	return (ret);
}
