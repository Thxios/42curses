/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_char_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:52:43 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/02 16:26:03 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_types.h"

int	print_char(t_format *format, va_list ap)
{
	char	val;

	(void)format;
	val = va_arg(ap, int);
	if (ft_putchar(val) == -1)
		return (-1);
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
	if (ft_putstr(val) == -1)
		return (-1);
	return (len);
}
