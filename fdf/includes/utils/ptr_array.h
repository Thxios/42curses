/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_array.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:42:06 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/06 23:09:43 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTR_ARRAY_H
# define PTR_ARRAY_H

# include "utils/array_hdr.h"

typedef struct s_ptr_arr
{
	int		size;
	int		capa;
	void	**arr;
}			t_ptr_arr;

t_ptr_arr	*new_ptr_array(void);
void		delete_ptr_array(t_ptr_arr *arr, void (*delete_elem)(void *));
void		push_ptr_array(t_ptr_arr *arr, void *value);
void		pop_ptr_array(t_ptr_arr *arr);

#endif
