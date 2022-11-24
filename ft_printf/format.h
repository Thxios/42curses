/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:14:16 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/22 17:06:47 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

typedef enum e_ftype
{
	INVALID = 0,
	CHAR,
	STR,
	PTR,
	DEC,
	INT,
	UINT,
	HEX_LOWER,
	HEX_UPPER,
	PERCENT
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

#endif
