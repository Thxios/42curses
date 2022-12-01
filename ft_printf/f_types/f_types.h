/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_types.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:33:25 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/01 13:48:36 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_TYPES_H
# define F_TYPES_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include "format/format.h"
# include "libft/libft.h"
# include "utils/utils.h"

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
