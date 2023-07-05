/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:42:38 by jimlee            #+#    #+#             */
/*   Updated: 2023/06/23 14:46:07 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "utils/vector.h"
# include "utils/matrix.h"

typedef enum e_cam_type
{
	ORTHOGRAPHIC,
	PERSPECTIVE
}	t_cam_type;

typedef struct s_camera
{
	char		*name;
	t_cam_type	type;
	// t_vec		(*world2scr)(t_vec);
	t_mat4		proj_mat;
}		t_camera;

t_camera	*camera(void);
void		init_camera(void);
void		change_camera_type(void);
void		set_proj_orthographic(void);
void		set_proj_perspective(void);
void		camera_zoom(double delta);

#endif
