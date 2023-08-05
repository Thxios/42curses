/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ortho.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:49:34 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/10 10:48:03 by jimlee           ###   ########.fr       */
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

void	init_ortho_config(void);
void	set_proj_orthographic(void);

#endif
