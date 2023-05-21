/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:11:58 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/21 17:42:58 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

#include "utils/vector.h"

typedef double	t_mat4[4][4];

void	matmul(t_mat4 a, t_mat4 b, t_mat4 out);
void	copy_matrix(t_mat4 dest, t_mat4 src);
void	matmul_inplace(t_mat4 a, t_mat4 b);
void	apply_to_vec(t_mat4 m, t_vec v, t_vec *out);

#endif
