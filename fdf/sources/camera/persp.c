/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:51:33 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/05 17:17:24 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "camera/camera.h"
#include "config.h"
#include "camera/persp.h"

t_persp	*get_persp_config(void)
{
	static t_persp	config = (t_persp){
		1, (double)HEIGHT / WIDTH,
		CAMERA_NEAR, CAMERA_FAR,
		0
	};

	return (&config);
}

void	init_persp_config(t_persp *conf)
{
	conf->f = 1 / tan(CAMERA_FOV / 360. * PI);
}

void	get_persp_proj_matrix(t_persp *cfg, t_mat4 out)
{
	double	mag_f;

	mag_f = pow(2, -cfg->mag) * cfg->f;
	out[0][0] = cfg->a * mag_f;
	out[0][1] = 0;
	out[0][2] = 0;
	out[0][3] = 0;
	out[1][0] = 0;
	out[1][1] = mag_f;
	out[1][2] = 0;
	out[1][3] = 0;
	out[2][0] = 0;
	out[2][1] = 0;
	out[2][2] = 2. / (cfg->far - cfg->near);
	out[2][3] = (cfg->near + cfg->far) / (cfg->near - cfg->far);
	out[3][0] = 0;
	out[3][1] = 0;
	out[3][2] = 1;
	out[3][3] = 0;
}
