/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_hex_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:38:14 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/01 13:43:05 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_types.h"

int	print_hex_lower(t_format *format, va_list ap)
{
	unsigned int	val;
	int				put_size;

	(void)format;
	val = va_arg(ap, unsigned int);
	put_size = get_len_num(val, 16);
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
	uintptr_t	val;
	int			put_size;

	(void)format;
	val = va_arg(ap, uintptr_t);
	if (val == 0)
	{
		ft_putstr_fd("(nil)", STDOUT_FILENO);
		return (5);
	}
	put_size = 2 + get_len_num_u(val, 16);
	ft_putstr_fd("0x", STDOUT_FILENO);
	ft_putnbr_base_u(val, "0123456789abcdef");
	return (put_size);
}
