/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_char_str_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:52:43 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/01 13:44:50 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_types_bonus.h"

int	ft_putchar_n(const char *buffer, int n)
{
	int	idx;

	idx = 0;
	while (idx < n)
	{
		ft_putchar_fd(buffer[idx], STDOUT_FILENO);
		idx++;
	}
	return (idx);
}

void	print_str_format(char *buffer, t_fstr *format)
{
	if (format->pre_pad)
		put_n_times(' ', format->pre_pad);
	ft_putchar_n(buffer, format->size);
	if (format->post_pad)
		put_n_times(' ', format->post_pad);
}

int	print_char(t_format *format, va_list ap)
{
	char	val;
	t_fstr	parsed;

	val = va_arg(ap, int);
	ft_memset(&parsed, 0, sizeof(parsed));
	parsed.size = 1;
	if (format->min_width > 1)
	{
		if (format->flag & LEFT_ALIGN)
			parsed.post_pad = format->min_width - 1;
		else
			parsed.pre_pad = format->min_width - 1;
	}
	print_str_format(&val, &parsed);
	return (ft_max(1, format->min_width));
}

int	print_str(t_format *format, va_list ap)
{
	char	*val;
	t_fstr	parsed;

	val = va_arg(ap, char *);
	ft_memset(&parsed, 0, sizeof(parsed));
	if (!val)
	{
		if ((format->flag & PRECISION) && (format->precision < 6))
			val = "";
		else
			val = "(null)";
	}
	parsed.size = ft_strlen(val);
	if ((format->flag & PRECISION) && (parsed.size > format->precision))
		parsed.size = format->precision;
	if (format->min_width > parsed.size)
	{
		if (format->flag & LEFT_ALIGN)
			parsed.post_pad = format->min_width - parsed.size;
		else
			parsed.pre_pad = format->min_width - parsed.size;
	}
	print_str_format(val, &parsed);
	return (ft_max(parsed.size, format->min_width));
}
