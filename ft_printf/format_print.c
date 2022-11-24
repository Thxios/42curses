/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:12:36 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/22 17:08:15 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_print.h"

int	print_format(const char *s, va_list ap, int *idx_ptr)
{
	int			idx;
	int			ret_size;
	t_format	*format;

	idx = *idx_ptr;
	format = (t_format *)malloc(sizeof(t_format));
	if (!format)
		return (-1);
	ft_memset(format, 0, sizeof(t_format));
	idx += parse_format_string(&s[idx], format);
	ret_size = print_argument(format, ap);
	free(format);
	*idx_ptr = idx;
	return (ret_size);
}
