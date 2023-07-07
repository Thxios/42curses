/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:11:58 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/07 17:31:25 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

#include "utils/vector.h"

typedef double	t_mat4[4][4];
typedef double	t_vec4[4];

void	matmul(t_mat4 a, t_mat4 b, t_mat4 out);
void	matmul_3d(t_mat4 a, t_mat4 b, t_mat4 out);
void	copy_matrix_3d(t_mat4 dest, t_mat4 src);
// void	matmul_inplace(t_mat4 a, t_mat4 b);
void	proj_vec_to_vec(t_mat4 m, t_vec v, t_vec *out);
void	proj_vec_to_vec4(t_mat4 m, t_vec v, t_vec4 out);

void print_matrix(t_mat4 mat);
void	print_vec4(t_vec4 v);

#endif
