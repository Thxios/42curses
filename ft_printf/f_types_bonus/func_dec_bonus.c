/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_dec_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:26:56 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/24 16:16:43 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_types_bonus.h"

int	print_dec(t_format *format, va_list ap)
{
	int	val;
	int	pad;
	int	put_size;

	(void)format;
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
	return (put_size);
}
