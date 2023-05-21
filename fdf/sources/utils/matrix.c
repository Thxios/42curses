/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:14:41 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/21 17:42:50 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/matrix.h"

void	matmul(t_mat4 a, t_mat4 b, t_mat4 out)
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			out[row][col] = a[row][0] * b[0][col] + a[row][1] * b[1][col]
				+ a[row][2] * b[2][col] + a[row][3] * b[3][col];
			col++;
		}
		row++;
	}
}

void	copy_matrix(t_mat4 dest, t_mat4 src)
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			dest[row][col] = src[row][col];
			col++;
		}
		row++;
	}
}

void	matmul_inplace(t_mat4 a, t_mat4 b)
{
	t_mat4	tmp;

	matmul(a, b, tmp);
	copy_matrix(a, tmp);
}

void	apply_to_vec(t_mat4 m, t_vec v, t_vec *out)
{
	out->x = v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + m[0][3];
	out->y = v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2] + m[1][3];
	out->z = v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2] + m[2][3];
}
