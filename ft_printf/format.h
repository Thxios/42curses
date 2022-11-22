/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:14:16 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/22 13:17:44 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

# include "libft/libft.h"

typedef enum e_ftype
{
	invalid = 0,
	c,
	s,
	p,
	d,
	i,
	u,
	x,
	X,
	percent
}	t_ftype;

typedef struct s_format
{
	int		left_align;				// '-'
	int		show_positive_sign;		// '+'
	int		show_positive_blank;	// ' '
	int		pad_zero;				// '0'
	int		sharp;					// '#'
	int		min_width;
	int		precision;				// '.'
	t_ftype	type;
}			t_format;

int			parse_format(const char *s, t_format *format);

#endif
