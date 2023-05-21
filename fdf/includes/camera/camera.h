/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:42:38 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/21 17:09:30 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "utils/vector.h"

typedef struct s_basis
{
	t_vec	x;
	t_vec	y;
	t_vec	z;
}		t_basis;


typedef struct s_camera
{
	char	*name;
	t_vec	(*world2scr)(t_vec);
}		t_camera;

t_camera	*camera(void);
void		init_camera(void);

#endif
