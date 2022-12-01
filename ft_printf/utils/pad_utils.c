/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:00:52 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/01 12:46:35 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	put_n_times(char c, int n)
{
	int	times;

	times = 0;
	while (times < n)
	{
		write(STDOUT_FILENO, &c, 1);
		times++;
	}
	return (n);
}
