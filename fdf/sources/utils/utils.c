/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:38:21 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/15 12:34:43 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils.h"
#include "utils/error.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	clip(int val, int min, int max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}

void	*safe_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		fatal_error("malloc fail");
	return (ret);
}

void	*safe_calloc(size_t n_elem, size_t elem_size)
{
	void	*ret;

	ret = malloc(n_elem * elem_size);
	if (!ret)
		fatal_error("malloc fail");
	ft_memset(ret, 0, n_elem * elem_size);
	return (ret);
}
