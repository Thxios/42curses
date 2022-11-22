/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:28:44 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/22 15:22:29 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_internal(const char *format_string, va_list ap)
{
	int	idx;
	int	size;

	(void)ap;
	idx = 0;
	size = 0;
	while (format_string[idx] != '\0')
	{
		if (format_string[idx] == '%')
		{
			size += print_format(format_string, &idx);
		}
		else
		{
			write(STDIN_FILENO, &format_string[idx], 1);
			size++;
			idx++;
		}
	}
	return (size);
}

int	ft_printf(const char *format_string, ...)
{
	va_list	ap;
	int		ret_code;

	va_start(ap, format_string);
	ret_code = ft_printf_internal(format_string, ap);
	va_end(ap);
	return (ret_code);
}
