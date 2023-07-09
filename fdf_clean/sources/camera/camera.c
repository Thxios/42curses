/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:42:31 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 17:13:47 by jimlee           ###   ########.fr       */
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

void	toggle_camera_type(void)
{
	if (camera()->type == PERSPECTIVE)
	{
		set_proj_orthographic();
	}
	else if (camera()->type == ORTHOGRAPHIC)
	{
		set_proj_perspective();
	}
}


void	init_camera()
{
	t_camera	*cam;

	cam = camera();
	cam->type = ORTHOGRAPHIC;
	cam->mag = 0;
	init_ortho_config();
	init_persp_config();
	set_proj_orthographic();
}
