/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:42:31 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/05 17:18:25 by jimlee           ###   ########.fr       */
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
	{
		get_ortho_config()->mag = get_persp_config()->mag;
		set_proj_orthographic();
	}
	else if (camera()->type == ORTHOGRAPHIC)
	{
		get_persp_config()->mag = get_ortho_config()->mag;
		set_proj_perspective();
	}
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
	init_persp_config(get_persp_config());
	set_proj_orthographic();
}