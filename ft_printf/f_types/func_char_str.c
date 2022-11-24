/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_char_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:52:43 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/22 17:37:08 by jimlee           ###   ########.fr       */
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
	if (val)
	{
		len = ft_strlen(val);
		ft_putstr_fd(val, STDOUT_FILENO);
	}
	else
	{
		len = 6;
		ft_putstr_fd("(null)", STDOUT_FILENO);
	}
	return (len);
}
