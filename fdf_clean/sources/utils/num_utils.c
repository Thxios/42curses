/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:38:21 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 19:31:00 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
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

double	maxf(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
