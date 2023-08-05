/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:55:11 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 19:29:36 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/vector.h"

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
