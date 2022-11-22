/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:12:36 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/22 15:32:12 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

int	print_format(const char *s, int *idx_ptr)
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
	free(format);
	*idx_ptr = idx;
	return (ret_size);
}
