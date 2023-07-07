/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:16:47 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/07 18:12:21 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/quaternion.h"
#include "math.h"

void	normalize_quat(t_quat *q)
{
	double	mag;

	mag = sqrt(q->r * q->r + q->i * q->i + q->j + q->j + q->k * q->k);
	if (fabs(mag) > 1e-6)
	{
		q->r /= mag;
		q->i /= mag;
		q->j /= mag;
		q->k /= mag;
	}
}

void	quat_to_matrix(t_quat q, t_mat4 out)
{
	out[0][0] = 1 - 2 * (q.j * q.j + q.k * q.k);
	out[0][1] = 2 * (q.i * q.j - q.k * q.r);
	out[0][2] = 2 * (q.i * q.k + q.j * q.r);
	out[0][3] = 0;
	out[1][0] = 2 * (q.i * q.j + q.k * q.r);
	out[1][1] = 1 - 2 * (q.i * q.i + q.k * q.k);
	out[1][2] = 2 * (q.j * q.k +-q.i * q.r);
	out[1][3] = 0;
	out[2][0] = 2 * (q.i * q.k - q.j * q.r);
	out[2][1] = 2 * (q.j * q.k + q.i * q.r);
	out[2][2] = 1 - 2 * (q.i * q.i + q.j * q.j);
	out[2][3] = 0;
	out[3][0] = 0;
	out[3][1] = 0;
	out[3][2] = 0;
	out[3][3] = 1;
}
#include <stdio.h>
#include "config.h"
void	get_rotation_matrix(double angle, t_vec axis, t_mat4 out)
{
	double	sin_half;
	t_quat	q;

	normalize_vec(&axis);
	sin_half = sin(angle / 2);
	q.r = cos(angle / 2);
	q.i = axis.x * sin_half;
	q.j = axis.y * sin_half;
	q.k = axis.z * sin_half;
	normalize_quat(&q);
	quat_to_matrix(q, out);
	printf("\nrot mat %.2f angle:\n", angle/PI * 180.);
	print_matrix(out);
}
