/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_invalid_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:50:24 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/02 16:27:08 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_types.h"

int	print_invalid(t_format *format, va_list ap)
{
	(void)format;
	(void)ap;
	return (0);
}

int	print_percent(t_format *format, va_list ap)
{
	(void)format;
	(void)ap;
	if (ft_putchar('%') == -1)
		return (-1);
	return (1);
}
