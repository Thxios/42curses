/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_hex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:38:14 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/25 16:38:32 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_types_bonus.h"

int	print_hex_lower(t_format *format, va_list ap)
{
	unsigned int	val;
	int				pad;
	int				put_size;

	val = va_arg(ap, unsigned int);
	put_size = get_len_num(val, 16);
	pad = ft_max(format->min_width - put_size, 0);
	ft_putnbr_base(val, "0123456789abcdef");
	return (put_size);
}

int	print_hex_upper(t_format *format, va_list ap)
{
	unsigned int	val;
	int				put_size;

	(void)format;
	val = va_arg(ap, unsigned int);
	put_size = get_len_num(val, 16);
	ft_putnbr_base(val, "0123456789ABCDEF");
	return (put_size);
}

int	print_ptr(t_format *format, va_list ap)
{
	unsigned long long	val;
	int					put_size;

	(void)format;
	val = va_arg(ap, unsigned long long);
	put_size = 2 + get_len_num_u(val, 16);
	write(STDOUT_FILENO, "0x", 2);
	ft_putnbr_base_u(val, "0123456789abcdef");
	return (put_size);
}
