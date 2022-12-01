/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:28:44 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/01 13:08:35 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf_internal(const char *format_string, va_list ap)
{
	int	idx;
	int	format_size;
	int	size;

	idx = 0;
	size = 0;
	while (format_string[idx] != '\0')
	{
		if (format_string[idx] == '%')
		{
			idx++;
			format_size = print_format(format_string, ap, &idx);
			if (format_size == -1)
				return (-1);
			size += format_size;
		}
		else
		{
			write(STDOUT_FILENO, &format_string[idx], 1);
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
