/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:28:47 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/30 14:40:02 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSP_H
# define PERSP_H

# include "utils/matrix.h"

typedef struct s_persp
{
	double	fov;
	double	f;
	double	a;
	double	near;
	double	far;
	double	mag;
}			t_persp;

t_persp	*get_persp_config(void);
void	get_persp_proj_matrix(t_persp *cfg, t_mat4 out);

#endif
