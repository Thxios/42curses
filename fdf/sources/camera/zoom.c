/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:40:45 by jimlee            #+#    #+#             */
/*   Updated: 2023/06/23 14:52:07 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera/camera.h"
#include "camera/ortho.h"
#include "camera/persp.h"
#include "utils/utils.h"

void	camera_zoom(double delta)
{
	if (camera()->type == ORTHOGRAPHIC)
	{
		get_ortho_config()->mag = clipf(
			get_ortho_config()->mag + delta * 0.1, -1, 1);
		set_proj_orthographic();
	}
	else if (camera()->type == PERSPECTIVE)
	{
		get_persp_config()->mag = clipf(
			get_persp_config()->mag + delta * 0.1, -1, 1);
		set_proj_perspective();
	}
}
