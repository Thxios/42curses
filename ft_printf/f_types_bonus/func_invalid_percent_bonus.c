/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_invalid_percent_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:50:24 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/01 13:45:01 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_types_bonus.h"

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
