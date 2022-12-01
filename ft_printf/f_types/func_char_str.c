/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_char_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:52:43 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/30 10:59:17 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_types.h"

int	print_char(t_format *format, va_list ap)
{
	char	val;

	(void)format;
	val = va_arg(ap, int);
	ft_putchar_fd(val, STDOUT_FILENO);
	return (1);
}

int	print_str(t_format *format, va_list ap)
{
	char	*val;
	int		len;

	(void)format;
	val = va_arg(ap, char *);
	if (!val)
		val = "(null)";
	len = ft_strlen(val);
	ft_putstr_fd(val, STDOUT_FILENO);
	return (len);
}
