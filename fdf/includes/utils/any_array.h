/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_array.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:42:06 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/05 18:01:59 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANY_ARRAY_H
# define ANY_ARRAY_H

# include "utils/array_hdr.h"

typedef struct s_any_arr
{
	int		size;
	int		capa;
	int		elem_size;
	void	*arr;
}			t_any_arr;

t_any_arr	*new_any_array(int elem_size);
void		delete_any_array(t_any_arr *arr);
void		push_any_array(t_any_arr *arr, void *value);
void		*index_any_array(t_any_arr *arr, int idx);
void		*pop_any_array(t_any_arr *arr);

#endif
