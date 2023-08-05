/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:28:47 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 17:11:29 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSP_H
# define PERSP_H

# include "utils/matrix.h"

typedef struct s_persp
{
	double	f;
	double	a;
	double	near;
	double	far;
}			t_persp;

// t_persp	*get_persp_config(void);
void	init_persp_config(void);
// void	get_persp_proj_matrix(t_persp *cfg, t_mat4 out, double mag);
void	set_proj_perspective(void);

#endif
