/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_types.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:33:25 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/22 17:49:17 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_TYPES_H
# define F_TYPES_H

# include <stdarg.h>
# include <unistd.h>
# include "format.h"
# include "libft/libft.h"

int	print_argument(t_format *format, va_list ap);

int	print_invalid(t_format *format, va_list ap);
int	print_percent(t_format *format, va_list ap);
int	print_char(t_format *format, va_list ap);
int	print_str(t_format *format, va_list ap);
int	print_hex_lower(t_format *format, va_list ap);
int	print_hex_upper(t_format *format, va_list ap);
int	print_ptr(t_format *format, va_list ap);
int	print_dec(t_format *format, va_list ap);
int	print_int(t_format *format, va_list ap);
int	print_uint(t_format *format, va_list ap);

#endif
