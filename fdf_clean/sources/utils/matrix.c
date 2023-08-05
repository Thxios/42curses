/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:14:41 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/10 10:36:39 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "utils/matrix.h"
#include "utils/vector.h"

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

void	matmul_3d(t_mat4 a, t_mat4 b, t_mat4 out)
{
	int	row;
	int	col;

	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			out[row][col] = a[row][0] * b[0][col] + a[row][1] * b[1][col]
				+ a[row][2] * b[2][col];
			col++;
		}
		row++;
	}
}

void	copy_matrix_3d(t_mat4 dest, t_mat4 src)
{
	int	row;
	int	col;

	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			dest[row][col] = src[row][col];
			col++;
		}
		row++;
	}
}

void	proj_vec_to_vec4(t_mat4 m, t_vec v, t_vec4 out)
{
	out[0] = v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + m[0][3];
	out[1] = v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2] + m[1][3];
	out[2] = v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2] + m[2][3];
	out[3] = v.x * m[3][0] + v.y * m[3][1] + v.z * m[3][2] + m[3][3];
}

void	adjust_unit_transform_matrix(t_mat4 mat)
{
	double	r1;
	double	r2;
	double	r3;

	r1 = sqrt(mat[0][0] * mat[0][0]
			+ mat[1][0] * mat[1][0] + mat[2][0] * mat[2][0]);
	r2 = sqrt(mat[0][1] * mat[0][1]
			+ mat[1][1] * mat[1][1] + mat[2][1] * mat[2][1]);
	r3 = sqrt(mat[0][2] * mat[0][2]
			+ mat[1][2] * mat[1][2] + mat[2][2] * mat[2][2]);
	mat[0][0] /= r1;
	mat[0][1] /= r1;
	mat[0][2] /= r1;
	mat[1][0] /= r2;
	mat[1][1] /= r2;
	mat[1][2] /= r2;
	mat[2][0] /= r3;
	mat[2][1] /= r3;
	mat[2][2] /= r3;
}
