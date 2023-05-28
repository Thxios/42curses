/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:42:31 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/25 01:50:08 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera/camera.h"
#include "camera/ortho.h"
#include "camera/persp.h"

t_camera	*camera()
{
	static t_camera	cam;

	return (&cam);
}

void	change_camera_type(void)
{
	if (camera()->type == PERSPECTIVE)
		set_proj_orthographic();
	else if (camera()->type == ORTHOGRAPHIC)
		set_proj_perspective();
}

void	set_proj_orthographic(void)
{
	t_camera	*cam;

	cam = camera();
	cam->type = ORTHOGRAPHIC;
	get_ortho_proj_matrix(get_ortho_config(), cam->proj_mat);
}

void	set_proj_perspective(void)
{
	t_camera	*cam;

	cam = camera();
	cam->type = PERSPECTIVE;
	get_persp_proj_matrix(get_persp_config(), cam->proj_mat);
}

void	init_camera()
{
	t_camera	*cam;

	cam = camera();
	set_proj_orthographic();
}
