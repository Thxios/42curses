/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_dec_int_uint_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:26:56 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/25 16:36:53 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_types_bonus.h"
#include <stdio.h>

int	get_len_num_precision(long long num, int precision)
{
	int	negative;
	int	ret_size;

	negative = 0;
	if (num < 0)
	{
		num = -num;
		negative = 1;
	}
	ret_size = ft_max(get_len_num(num, 10), precision);
	if (negative)
		ret_size++;
	return (ret_size);
}

void	ft_putnbr_precision(long long num, int precision)
{
	int	size;

	if (num < 0)
		num = -num;
	size = get_len_num(num, 10);
	if (precision > size)
		put_n_times('0', precision - size);
	ft_putnbr(num);
}

int	print_dec(t_format *format, va_list ap)
{
	int	val;
	int	pad;
	int	put_size;
	char	prefix;

	val = va_arg(ap, int);
	put_size = get_len_num_precision(val, format->precision);
	prefix = 0;
	if (val < 0)
		prefix = '-';
	if (val > 0 && (format->show_positive_blank || format->show_positive_sign))
	{
		if (format->show_positive_blank)
			prefix = ' ';
		else if (format->show_positive_sign)
			prefix = '+';
		put_size++;
	}
	pad = ft_max(format->min_width - put_size, 0);
	if (!format->left_align && !format->pad_zero)
		put_n_times(' ', pad);
	if (prefix)
		ft_putchar_fd(prefix, STDOUT_FILENO);
	if (format->pad_zero && !format->left_align)
		put_n_times('0', pad);
	ft_putnbr_precision(val, format->precision);
	if (format->left_align)
		put_n_times(' ', pad);
	return (put_size + pad);
}

int	print_int(t_format *format, va_list ap)
{
	int	val;
	int	pad;
	int	put_size;

	val = va_arg(ap, int);
	put_size = get_len_num(val, 10);
	if (val > 0 && (format->show_positive_blank || format->show_positive_sign))
		put_size++;
	pad = ft_max(format->min_width - put_size, 0);
	if (!format->left_align && !format->pad_zero)
		put_n_times(' ', pad);
	if ((val > 0) && format->show_positive_sign)
		ft_putchar_fd('+', STDOUT_FILENO);
	else if ((val > 0) && format->show_positive_blank)
		ft_putchar_fd(' ', STDOUT_FILENO);
	if (format->pad_zero && !format->left_align)
		put_n_times('0', pad);
	ft_putnbr(val);
	if (format->left_align)
		put_n_times(' ', pad);
	return (put_size + pad);
}

int	print_uint(t_format *format, va_list ap)
{
	unsigned int	val;
	int				pad;
	int				put_size;

	val = va_arg(ap, unsigned int);
	put_size = get_len_num(val, 10);
	if (val > 0 && (format->show_positive_blank || format->show_positive_sign))
		put_size++;
	pad = ft_max(format->min_width - put_size, 0);
	if (!format->left_align && !format->pad_zero)
		put_n_times(' ', pad);
	if ((val > 0) && format->show_positive_sign)
		ft_putchar_fd('+', STDOUT_FILENO);
	else if ((val > 0) && format->show_positive_blank)
		ft_putchar_fd(' ', STDOUT_FILENO);
	if (format->pad_zero && !format->left_align)
		put_n_times('0', pad);
	ft_putnbr(val);
	if (format->left_align)
		put_n_times(' ', pad);
	return (put_size + pad);
}
