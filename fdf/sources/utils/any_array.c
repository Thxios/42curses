/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:43:56 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/05 18:06:26 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/any_array.h"
#include "utils/utils.h"
#include "libft.h"

t_any_arr	*new_any_array(int elem_size)
{
	t_any_arr	*ret;

	ret = safe_malloc(sizeof(t_any_arr));
	ret->capa = INITIAL_CAPA;
	ret->size = 0;
	ret->elem_size = elem_size;
	ret->arr = safe_calloc(ret->capa, ret->elem_size);
	return (ret);
}

void	push_any_array(t_any_arr *arr, void *value)
{
	void	*new_arr;

	if (arr->size == arr->capa)
	{
		new_arr = safe_calloc(arr->capa * 2, arr->elem_size);
		ft_memcpy(new_arr, arr->arr, arr->size * arr->elem_size);
		free(arr->arr);
		arr->arr = new_arr;
		arr->capa *= 2;
	}
	ft_memcpy(arr->arr + arr->size * arr->elem_size, value, , arr->elem_size);
	arr->size++;
}

void	pop_any_array(t_any_arr *arr)
{
	if (arr->size)
		arr->size--;
}

void	delete_any_array(t_any_arr *arr)
{
	free(arr->arr);
	free(arr);
}

void	*index_any_array(t_any_arr *arr, int idx)
{
	return (arr->arr + idx * arr->elem_size);
}
