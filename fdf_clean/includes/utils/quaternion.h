/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:15:03 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 16:19:29 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H

# include "utils/matrix.h"
# include "utils/vector.h"

typedef struct s_quat
{
	double	r;
	double	i;
	double	j;
	double	k;
}			t_quat;

void	get_rotation_matrix(double angle, t_vec axis, t_mat4 out);

#endif
