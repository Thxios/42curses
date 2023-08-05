/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:40:45 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 21:06:30 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera/camera.h"
#include "utils/utils.h"

void	zoom_camera(double delta)
{
	t_camera	*cam;

	cam = camera();
	cam->mag = clipf(cam->mag + delta * 0.1, -1, 1);
	if (cam->type == ORTHOGRAPHIC)
		set_proj_orthographic();
	else if (cam->type == PERSPECTIVE)
		set_proj_perspective();
}
