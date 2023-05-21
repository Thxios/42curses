/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ortho_trans.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:49:34 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/21 17:44:25 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORTHO_TRANS_H
# define ORTHO_TRANS_H

# include "utils/vector.h"
# include "utils/matrix.h"

typedef struct s_ortho
{
	double	left;
	double	right;
	double	top;
	double	bottom;
	double	near;
	double	far;
	t_mat4	projection;
}			t_ortho;


t_vec	ortho_world2scr(t_vec);

#endif
