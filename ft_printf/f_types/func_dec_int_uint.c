/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_dec_int_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:26:56 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/02 16:22:24 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_types.h"

int	print_dec(t_format *format, va_list ap)
{
	int	val;
	int	put_size;

	(void)format;
	val = va_arg(ap, int);
	put_size = get_len_num(val, 10);
	if (ft_putnbr(val) == -1)
		return (-1);
	return (put_size);
}

int	print_int(t_format *format, va_list ap)
{
	int	val;
	int	put_size;

	(void)format;
	val = va_arg(ap, int);
	put_size = get_len_num(val, 10);
	if (ft_putnbr(val) == -1)
		return (-1);
	return (put_size);
}

int	print_uint(t_format *format, va_list ap)
{
	unsigned int	val;
	int				put_size;

	(void)format;
	val = va_arg(ap, unsigned int);
	put_size = get_len_num(val, 10);
	if (ft_putnbr(val) == -1)
		return (-1);
	return (put_size);
}
