/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_invalid_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:50:24 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/25 16:38:47 by jimlee           ###   ########.fr       */
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
	write(STDOUT_FILENO, "%", 1);
	return (1);
}
