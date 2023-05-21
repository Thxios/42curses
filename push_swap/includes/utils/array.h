/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:42:06 by jimlee            #+#    #+#             */
/*   Updated: 2023/04/30 04:33:51 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

typedef struct s_array
{
	int	size;
	int	capa;
	int	*arr;
}		t_array;

t_array	*new_array(void);
t_array	*copy_array(t_array *arr);
void	delete_array(t_array *arr);
void	push_array(t_array *arr, int value);
void	pop_array(t_array *arr);

#endif
