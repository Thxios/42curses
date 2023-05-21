/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:34:41 by jimlee            #+#    #+#             */
/*   Updated: 2023/04/30 04:50:03 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "context/context.h"

void	init_context(t_array *arr)
{
	t_state	*context;
	int		idx;

	context = get_context();
	context->a = new_deque();
	context->b = new_deque();
	context->log = new_array();
	idx = arr->size - 1;
	while (idx >= 0)
	{
		push_back(context->a, arr->arr[idx]);
		idx--;
	}
}

void	delete_context(void)
{
	t_state	*context;

	context = get_context();
	delete_deque(context->a);
	delete_deque(context->b);
	delete_array(context->log);
	context->a = NULL;
	context->b = NULL;
	context->log = NULL;
}
