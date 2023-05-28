/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:51:33 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/25 01:59:36 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "utils/vector.h"
#include "camera/camera.h"
#include "config.h"
#include "camera/persp.h"

t_persp	*get_persp_config(void)
{
	static t_persp	config = (t_persp){
		CAMERA_FOV, 1 / tan(CAMERA_FOV / 360. * PI),
		(double)HEIGHT / WIDTH, CAMERA_FAR / (CAMERA_FAR - CAMERA_NEAR),
		CAMERA_NEAR, CAMERA_FAR
	};

	return (&config);
}

void	get_persp_proj_matrix(t_persp *cfg, t_mat4 out)
{
	out[0][0] = cfg->a * cfg->f;
	out[0][1] = 0;
	out[0][2] = 0;
	out[0][3] = 0;
	out[1][0] = 0;
	out[1][1] = cfg->f;
	out[1][2] = 0;
	out[1][3] = 0;
	out[2][0] = 0;
	out[2][1] = 0;
	// out[2][2] = cfg->q;
	// out[2][3] = -cfg->q * cfg->near;
	out[2][2] = 2. / (cfg->far - cfg->near);
	out[2][3] = (cfg->near + cfg->far) / (cfg->near - cfg->far);
	out[3][0] = 0;
	out[3][1] = 0;
	out[3][2] = 1;
	out[3][3] = 0;
}
