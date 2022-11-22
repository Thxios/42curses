/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:28:44 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/22 12:14:50 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_internal(const char *format_string, va_list *ap)
{

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
