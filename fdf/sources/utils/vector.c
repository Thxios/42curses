/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:55:11 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/17 15:29:36 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/vector.h"
#include "math.h"

t_vec	add(t_vec a, t_vec b)
{
	return ((t_vec){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_vec	sub(t_vec a, t_vec b)
{
	return ((t_vec){a.x - b.x, a.y - b.y, a.z - b.z});

}

double	dot(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec	cross(t_vec a, t_vec b)
{
	return ((t_vec){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x - b.z,
		a.x * b.y - a.y * b.x
	});
}

void	normalize_vec(t_vec *v)
{
	double	mag;

	mag = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	if (fabs(mag) > 1e-6)
	{
		v->x /= mag;
		v->y /= mag;
		v->z /= mag;
	}
}
