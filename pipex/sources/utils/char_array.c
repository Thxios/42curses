/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:43:56 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/07 22:57:02 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/char_array.h"
#include "utils/utils.h"
#include "libft/libft.h"

t_chr_arr	*new_chr_array(void)
{
	t_chr_arr	*ret;

	ret = safe_malloc(sizeof(t_chr_arr));
	ret->capa = INITIAL_CAPA;
	ret->size = 0;
	ret->arr = safe_calloc(ret->capa, sizeof(char));
	return (ret);
}

void	push_chr_array(t_chr_arr *arr, char value)
{
	char	*new_arr;

	if (arr->size == arr->capa)
	{
		new_arr = safe_calloc(arr->capa * 2, sizeof(char));
		ft_memcpy(new_arr, arr->arr, arr->size * sizeof(char));
		free(arr->arr);
		arr->arr = new_arr;
		arr->capa *= 2;
	}
	arr->arr[arr->size] = value;
	arr->size++;
}

void	pop_chr_array(t_chr_arr *arr)
{
	if (arr->size)
		arr->size--;
}

void	delete_chr_array(t_chr_arr *arr)
{
	free(arr->arr);
	free(arr);
}

char	*to_string(t_chr_arr *arr)
{
	char	*s;

	s = safe_malloc((arr->size + 1) * sizeof(char));
	ft_strlcpy(s, arr->arr, arr->size + 1);
	return (s);
}
