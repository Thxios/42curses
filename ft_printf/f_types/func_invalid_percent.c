/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_invalid_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:50:24 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/30 11:00:41 by jimlee           ###   ########.fr       */
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
	ft_putchar_fd('%', STDOUT_FILENO);
	return (1);
}
