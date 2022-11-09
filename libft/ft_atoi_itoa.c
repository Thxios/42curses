/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:55:36 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/08 19:58:13 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || (c == 32));
}

int	ft_atoi(const char *nptr)
{
	int			idx;
	int			sign;
	long long	ret;

	idx = 0;
	while (ft_isspace(nptr[idx]))
		idx++;
	sign = 1;
	if ((nptr[idx] == '-') || (nptr[idx] == '+'))
	{
		if (nptr[idx] == '-')
			sign = -sign;
		idx++;
	}
	ret = 0;
	while (ft_isdigit(nptr[idx]))
	{
		ret *= 10;
		ret += nptr[idx] - '0';
		idx++;
	}
	return ((int)(sign * ret));
}
