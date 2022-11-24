/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:05:47 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/24 15:41:04 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_PRINT_H
# define FORMAT_PRINT_H

# include <stdlib.h>
# include <stdarg.h>
# include "format.h"
# include "format_parser.h"
# include "libft/libft.h"

int	print_argument(t_format *format, va_list ap);
int	print_format(const char *s, va_list ap, int *idx_ptr);

#endif
