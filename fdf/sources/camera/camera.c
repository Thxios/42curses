/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:42:31 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/15 15:06:59 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera/camera.h"
#include "camera/orthgraphic/ortho_trans.h"

t_camera	*camera()
{
	static t_camera	cam;

	return (&cam);
}

void	set_proj_orthographic(void)
{
	t_camera	*cam;

	cam = camera();
	cam->world2scr = ortho_world2scr;
}

void	init_camera()
{
	t_camera	*cam;

	cam = camera();

}
