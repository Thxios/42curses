/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:28:44 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/21 02:33:30 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format_string, ...)
{
	va_list	ap;
	int		ret_code;

	va_start(ap, format_string);
	va_end(ap);
	return (ret_code);
}
