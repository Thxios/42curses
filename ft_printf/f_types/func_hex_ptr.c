/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_hex_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:38:14 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/22 17:47:08 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_types.h"

int	get_len_num_hex(long long n)
{
	int	len_num;

	len_num = 0;
	if (n <= 0)
		len_num++;
	while (n)
	{
		n /= 0x10;
		len_num++;
	}
	return (len_num);
}

void	ft_putnbr_hex(long long n_int64, char *base)
{
	long long	heximal;
	int			digit;

	heximal = 1;
	while (n_int64 / heximal >= 0x10)
		heximal = heximal * 0x10;
	while (heximal > 0)
	{
		digit = n_int64 / heximal;
		ft_putchar_fd(base[digit], STDOUT_FILENO);
		n_int64 -= digit * heximal;
		heximal = heximal / 10;
	}
}

int	print_hex_lower(t_format *format, va_list ap)
{
	unsigned int	val;

	(void)format;
	val = va_arg(ap, unsigned int);
	ft_putnbr_hex(val, "0123456789abcdef");
	return (get_len_num_hex(val));
}

int	print_hex_upper(t_format *format, va_list ap)
{
	unsigned int	val;

	(void)format;
	val = va_arg(ap, unsigned int);
	ft_putnbr_hex(val, "0123456789ABCDEF");
	return (get_len_num_hex(val));
}

int	print_ptr(t_format *format, va_list ap)
{
	unsigned long long	val;

	(void)format;
	val = va_arg(ap, unsigned long long);
	ft_putnbr_hex(val, "0123456789abcdef");
	return (get_len_num_hex(val));
}
