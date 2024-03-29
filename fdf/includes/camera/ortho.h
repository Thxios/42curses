/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ortho.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:49:34 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 17:12:49 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORTHO_H
# define ORTHO_H

# include "utils/matrix.h"

typedef struct s_ortho
{
	double	left;
	double	right;
	double	top;
	double	bottom;
	double	near;
	double	far;
}			t_ortho;

// t_ortho	*get_ortho_config(void);
void	init_ortho_config(void);
// void	get_ortho_proj_matrix(t_ortho *cfg, t_mat4 out, double mag);
void	set_proj_orthographic(void);

#endif
