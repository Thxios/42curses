/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:51:33 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 21:07:46 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "config.h"
#include "camera/camera.h"
#include "camera/persp.h"

t_persp	*get_persp_config(void)
{
	static t_persp	config;

	return (&config);
}

void	init_persp_config(void)
{
	t_persp	*conf;

	conf = get_persp_config();
	conf->f = 1 / tan(CAMERA_PERSP_FOV / 360. * PI);
	conf->a = (double)HEIGHT / WIDTH;
	conf->near = CAMERA_NEAR;
	conf->far = CAMERA_FAR;
}

void	get_persp_proj_matrix(t_persp *cfg, t_mat4 out, double mag)
{
	double	mag_f;

	mag_f = pow(2, -mag) * cfg->f;
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

void	set_proj_perspective(void)
{
	t_camera	*cam;

	cam = camera();
	cam->type = PERSPECTIVE;
	get_persp_proj_matrix(get_persp_config(), cam->proj_mat, cam->mag);
}
