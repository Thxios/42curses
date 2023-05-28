/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:45:47 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/25 01:19:44 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

t_vec	add(t_vec a, t_vec b);
t_vec	sub(t_vec a, t_vec b);
double	dot(t_vec a, t_vec b);
t_vec	cross(t_vec a, t_vec b);
void	normalize_vec(t_vec *v);

void	print_vec(t_vec v);

#endif
