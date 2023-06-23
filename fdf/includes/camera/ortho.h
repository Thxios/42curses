/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ortho.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:49:34 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/30 14:38:49 by jimlee           ###   ########.fr       */
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
	double	mag;
}			t_ortho;

t_ortho	*get_ortho_config(void);
void	get_ortho_proj_matrix(t_ortho *cfg, t_mat4 out);

#endif
