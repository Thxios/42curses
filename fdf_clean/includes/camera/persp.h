/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:28:47 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/10 10:48:09 by jimlee           ###   ########.fr       */
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

void	init_persp_config(void);
void	set_proj_perspective(void);

#endif
