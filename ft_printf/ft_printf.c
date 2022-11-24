/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:28:44 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/22 18:02:24 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf_internal(const char *format_string, va_list ap)
{
	int	idx;
	int	size;

	idx = 0;
	size = 0;
	while (format_string[idx] != '\0')
	{
		// printf("print %02d: \'%c\'\n", idx, format_string[idx]);
		if (format_string[idx] == '%')
		{
			idx++;
			size += print_format(format_string, ap, &idx);
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
