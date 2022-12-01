/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_ptr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:53:44 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/01 13:36:50 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_types_bonus.h"

int	parse_prec_pad_ptr(t_format *format, unsigned long long num, t_fhex *parsed)
{
	int	abs_num_len;
	int	num_len;

	abs_num_len = get_len_num_u(num, 16);
	num_len = abs_num_len;
	if ((format->flag & PRECISION) && (format->precision > abs_num_len))
	{
		num_len = format->precision;
		parsed->mid_zero = num_len - abs_num_len;
	}
	if (parsed->prefix)
		num_len += ft_strlen(parsed->prefix);
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

void	print_ptr_format(unsigned long long num, t_fhex *format, char *base)
{
	if (format->pre_pad)
		put_n_times(' ', format->pre_pad);
	if (format->prefix)
		ft_putstr_fd(format->prefix, STDOUT_FILENO);
	if (format->mid_zero)
		put_n_times('0', format->mid_zero);
	ft_putnbr_base_u(num, base);
	if (format->post_pad)
		put_n_times(' ', format->post_pad);
}

int	print_null_ptr(t_format *format)
{
	t_fstr	parsed;

	ft_memset(&parsed, 0, sizeof(parsed));
	parsed.size = 5;
	if (format->min_width > parsed.size)
	{
		if (format->flag & LEFT_ALIGN)
			parsed.post_pad = format->min_width - parsed.size;
		else
			parsed.pre_pad = format->min_width - parsed.size;
	}
	if (parsed.pre_pad)
		put_n_times(' ', parsed.pre_pad);
	ft_putstr_fd("(nil)", STDOUT_FILENO);
	if (parsed.post_pad)
		put_n_times(' ', parsed.post_pad);
	return (ft_max(parsed.size, format->min_width));
}

int	print_ptr(t_format *format, va_list ap)
{
	uintptr_t	val;
	int			put_size;
	t_fhex		parsed;

	val = va_arg(ap, uintptr_t);
	ft_memset(&parsed, 0, sizeof(t_fhex));
	if (val == 0)
		return (print_null_ptr(format));
	parsed.prefix = "0x";
	put_size = parse_prec_pad_ptr(format, val, &parsed);
	print_ptr_format(val, &parsed, "0123456789abcdef");
	return (put_size);
}
