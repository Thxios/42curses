/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:43:56 by jimlee            #+#    #+#             */
/*   Updated: 2023/06/27 20:02:06 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/ptr_array.h"
#include "utils/utils.h"
#include "libft.h"

t_ptr_arr	*new_chr_array(void)
{
	t_ptr_arr	*ret;

	ret = safe_malloc(sizeof(t_ptr_arr));
	ret->capa = INITIAL_CAPA;
	ret->size = 0;
	ret->arr = safe_calloc(ret->capa, sizeof(void *));
	return (ret);
}

void	push_chr_array(t_ptr_arr *arr, void *value)
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

void	pop_chr_array(t_ptr_arr *arr)
{
	if (arr->size)
		arr->size--;
}

void	delete_chr_array(t_ptr_arr *arr)
{
	free(arr->arr);
	free(arr);
}
