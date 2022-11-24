/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_dec_int_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:26:56 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/22 18:03:40 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_types.h"

int	get_len_num_dec(long long n)
{
	int	len_num;

	len_num = 0;
	if (n <= 0)
		len_num++;
	while (n)
	{
		n /= 10;
		len_num++;
	}
	return (len_num);
}

int	print_dec(t_format *format, va_list ap)
{
	int	val;

	(void)format;
	val = va_arg(ap, int);
	ft_putnbr_fd(val, STDOUT_FILENO);
	return (get_len_num_dec(val));
}

int	print_int(t_format *format, va_list ap)
{
	int	val;

	(void)format;
	val = va_arg(ap, int);
	ft_putnbr_fd(val, STDOUT_FILENO);
	return (get_len_num_dec(val));
}

int	print_uint(t_format *format, va_list ap)
{
	unsigned int	val;

	(void)format;
	val = va_arg(ap, unsigned int);
	ft_putnbr_fd(val, STDOUT_FILENO);
	return (get_len_num_dec(val));
}
