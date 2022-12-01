/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_dec_int_uint_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:26:56 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/29 17:36:24 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_types_bonus.h"

int	parse_prec_pad_dec(t_format *format, long long num, t_fdec *parsed)
{
	int	abs_num_len;
	int	num_len;

	abs_num_len = 0;
	if (num >= 0)
		abs_num_len = get_len_num(num, 10);
	num_len = abs_num_len;
	if ((format->flag & PRECISION) && (format->precision > abs_num_len))
	{
		num_len = format->precision;
		parsed->mid_zero = num_len - abs_num_len;
	}
	if (parsed->sign)
		num_len++;
	if (format->min_width > num_len)
	{
		if (format->flag & LEFT_ALIGN)
			parsed->post_pad = format->min_width - num_len;
		else if ((parsed->mid_zero == 0) && (format->flag & PAD_ZERO))
			parsed->mid_zero = format->min_width - num_len;
		else
			parsed->pre_pad = format->min_width - num_len;
	}
	return (ft_max(num_len, format->min_width));
}

void	print_dec_format(long long num, t_fdec *format)
{
	if (format->pre_pad)
		put_n_times(' ', format->pre_pad);
	if (format->sign)
		ft_putchar_fd(format->sign, STDOUT_FILENO);
	if (format->mid_zero)
		put_n_times('0', format->mid_zero);
	if (num >= 0)
		ft_putnbr(num);
	if (format->post_pad)
		put_n_times(' ', format->post_pad);
}

int	print_dec(t_format *format, va_list ap)
{
	long long	val;
	int			put_size;
	t_fdec		parsed;

	val = va_arg(ap, int);
	ft_memset(&parsed, 0, sizeof(parsed));
	if (val < 0)
	{
		parsed.sign = '-';
		val = -val;
	}
	else if (format->flag & SHOW_POS_SIGN)
		parsed.sign = '+';
	else if (format->flag & SHOW_POS_BLANK)
		parsed.sign = ' ';
	if ((format->flag & PRECISION) && (format->precision == 0) && (val == 0))
		val = -1;
	put_size = parse_prec_pad_dec(format, val, &parsed);
	print_dec_format(val, &parsed);
	return (put_size);
}

int	print_int(t_format *format, va_list ap)
{
	long long	val;
	int			put_size;
	t_fdec		parsed;

	val = va_arg(ap, int);
	ft_memset(&parsed, 0, sizeof(t_fdec));
	if (val < 0)
	{
		parsed.sign = '-';
		val = -val;
	}
	else if (format->flag & SHOW_POS_SIGN)
		parsed.sign = '+';
	else if (format->flag & SHOW_POS_BLANK)
		parsed.sign = ' ';
	if ((format->flag & PRECISION) && (format->precision == 0) && (val == 0))
		val = -1;
	put_size = parse_prec_pad_dec(format, val, &parsed);
	print_dec_format(val, &parsed);
	return (put_size);
}

int	print_uint(t_format *format, va_list ap)
{
	long long	val;
	int			put_size;
	t_fdec		parsed;

	val = va_arg(ap, unsigned int);
	ft_memset(&parsed, 0, sizeof(t_fdec));
	if ((format->flag & PRECISION) && (format->precision == 0) && (val == 0))
		val = -1;
	put_size = parse_prec_pad_dec(format, val, &parsed);
	print_dec_format(val, &parsed);
	return (put_size);
}
