/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_array.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:42:06 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/07 23:36:40 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_ARRAY_H
# define CHAR_ARRAY_H

# include "utils/array_hdr.h"

typedef struct s_chr_arr
{
	int		size;
	int		capa;
	char	*arr;
}			t_chr_arr;

t_chr_arr	*new_chr_array(void);
void		delete_chr_array(t_chr_arr *arr);
void		push_chr_array(t_chr_arr *arr, char value);
void		pop_chr_array(t_chr_arr *arr);

char		*to_string(t_chr_arr *arr);

#endif
