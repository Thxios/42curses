/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:51:29 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/13 15:54:46 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_isspace(int c)
{
	return ((9 <= c && c <= 13) || (c == 32));
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (4);
	else
		return (0);
}

int	ft_atoi(char *nptr)
{
	int	idx;
	int	sign;
	int	ret;

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
		ret = 10 * ret + sign * (nptr[idx] - '0');
		idx++;
	}
	while (ft_isspace(nptr[idx]))
		idx++;
	if (nptr[idx] != '\0')
		return (-1);
	return (ret);
}
