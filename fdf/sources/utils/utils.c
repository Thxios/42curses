/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:38:21 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/05 17:46:07 by jimlee           ###   ########.fr       */
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

double	clipf(double val, double min, double max)
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

char	**split_and_size(char *s, int *size)
{
	char	**ret;
	int		cnt;

	ret = ft_split(s, ' ');
	cnt = 0;
	while (ret[cnt])
		cnt++;
	*size = cnt;
	return (ret);
}

int	*map_atoi_to_splited(char *s, int *size)
{
	char	**ret;
	int		*arr;
	int		cnt;

	ret = ft_split(s, ' ');
	cnt = 0;
	while (ret[cnt])
		cnt++;
	*size = cnt;
	arr = safe_calloc(cnt, sizeof(int));
	while (cnt--)
	{
		arr[cnt] = ft_atoi(ret[cnt]);
		free(ret[cnt]);
	}
	free(ret);
	return (arr);
}

