/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:43:56 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/08 14:37:53 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/str_array.h"
#include "utils/utils.h"
#include "libft/libft.h"

t_str_arr	*new_str_array(void)
{
	t_str_arr	*ret;

	ret = safe_malloc(sizeof(t_str_arr));
	ret->capa = INITIAL_CAPA;
	ret->size = 0;
	ret->arr = safe_calloc(ret->capa, sizeof(char *));
	return (ret);
}

void	push_str_array(t_str_arr *arr, char *value)
{
	char	**new_arr;

	if (arr->size == arr->capa)
	{
		new_arr = safe_calloc(arr->capa * 2, sizeof(char *));
		ft_memcpy(new_arr, arr->arr, arr->size * sizeof(char *));
		free(arr->arr);
		arr->arr = new_arr;
		arr->capa *= 2;
	}
	arr->arr[arr->size] = value;
	arr->size++;
}

void	pop_str_array(t_str_arr *arr)
{
	if (arr->size)
		arr->size--;
}

void	delete_str_array(t_str_arr *arr)
{
	int	idx;

	idx = 0;
	while (idx < arr->size)
	{
		free(arr->arr[idx]);
		idx++;
	}
	free(arr->arr);
	free(arr);
}

char	**to_2d_str_arr(t_str_arr *arr)
{
	char	**ret;
	int		idx;

	ret = safe_calloc(arr->size + 1, sizeof(char *));
	idx = 0;
	while (idx < arr->size)
	{
		ret[idx] = ft_strdup(arr->arr[idx]);
		idx++;
	}
	return (ret);
}
