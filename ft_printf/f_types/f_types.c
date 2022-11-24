/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_types.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:43:56 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/22 17:51:47 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_types.h"

int	print_argument(t_format *format, va_list ap)
{
	static int	(*arg_print_func[10])(t_format *, va_list)
		= {print_invalid, print_char, print_str, print_ptr, print_dec,
		print_int, print_uint, print_hex_lower, print_hex_upper, print_percent};
	int	format_type;
	int	ret_size;

	format_type = (int)format->type;
	ret_size = (*arg_print_func[format_type])(format, ap);
	return (ret_size);
}
