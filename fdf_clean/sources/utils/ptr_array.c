/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:43:56 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 19:27:24 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "utils/ptr_array.h"
#include "utils/utils.h"

t_ptr_arr	*new_ptr_array(void)
{
	t_ptr_arr	*ret;

	ret = safe_malloc(sizeof(t_ptr_arr));
	ret->capa = INITIAL_CAPA;
	ret->size = 0;
	ret->arr = safe_calloc(ret->capa, sizeof(void *));
	return (ret);
}

void	push_ptr_array(t_ptr_arr *arr, void *value)
{
	void	**new_arr;

	if (arr->size == arr->capa)
	{
		new_arr = safe_calloc(arr->capa * 2, sizeof(void *));
		ft_memcpy(new_arr, arr->arr, arr->size * sizeof(void *));
		free(arr->arr);
		arr->arr = new_arr;
		arr->capa *= 2;
	}
	arr->arr[arr->size] = value;
	arr->size++;
}

void	pop_ptr_array(t_ptr_arr *arr)
{
	if (arr->size)
		arr->size--;
}

void	delete_ptr_array(t_ptr_arr *arr, void (*delete_elem)(void *))
{
	int	idx;

	if (delete_elem)
	{
		idx = 0;
		while (idx < arr->size)
		{
			delete_elem(arr->arr[idx]);
			idx++;
		}
	}
	free(arr->arr);
	free(arr);
}
