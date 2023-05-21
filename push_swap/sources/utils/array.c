/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:43:56 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/09 16:59:11 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/array_hdr.h"
#include "utils/safe_malloc.h"
#include "libft/libft.h"

t_array	*new_array(void)
{
	t_array	*ret;

	ret = safe_malloc(sizeof(t_array));
	ret->capa = INITIAL_CAPA;
	ret->size = 0;
	ret->arr = safe_calloc(ret->capa, sizeof(int));
	return (ret);
}

t_array	*copy_array(t_array *arr)
{
	t_array	*ret;

	ret = safe_malloc(sizeof(t_array));
	ret->capa = arr->capa;
	ret->size = arr->size;
	ret->arr = safe_calloc(ret->capa, sizeof(int));
	ft_memcpy(ret->arr, arr->arr, sizeof(int) * arr->size);
	return (ret);
}

void	push_array(t_array *arr, int value)
{
	int	*new_arr;

	if (arr->size == arr->capa)
	{
		new_arr = safe_calloc(arr->capa * 2, sizeof(int));
		ft_memcpy(new_arr, arr->arr, arr->size * sizeof(int));
		free(arr->arr);
		arr->arr = new_arr;
		arr->capa *= 2;
	}
	arr->arr[arr->size] = value;
	arr->size++;
}

void	pop_array(t_array *arr)
{
	if (arr->size)
		arr->size--;
}

void	delete_array(t_array *arr)
{
	free(arr->arr);
	free(arr);
}
