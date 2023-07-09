/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:40:45 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 17:13:59 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera/camera.h"
#include "utils/utils.h"

void	zoom_camera(double delta)
{
	t_camera	*cam;

	cam = camera();
	cam->mag = clipf(cam->mag + delta * 0.1, -1, 1);
}
