/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:58:27 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/29 01:07:06 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "utils/error.h"
#include "libft/libft.h"

void	*safe_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		fatal_error("malloc() fail");
	return (ret);
}

void	*safe_calloc(size_t n_elem, size_t elem_size)
{
	void	*ret;

	ret = safe_malloc(n_elem * elem_size);
	ft_memset(ret, 0, n_elem * elem_size);
	return (ret);
}

void	free_2d_str_arr(char **arr)
{
	int	idx;

	idx = 0;
	while (arr[idx])
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
}
