/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ortho.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:51:33 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/10 10:08:05 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "config.h"
#include "camera/ortho.h"
#include "camera/camera.h"

t_ortho	*get_ortho_config(void)
{
	static t_ortho	config;

	return (&config);
}

void	init_ortho_config(void)
{
	double	a;
	t_ortho	*conf;

	a = (double)HEIGHT / WIDTH;
	conf = get_ortho_config();
	conf->left = -CAMERA_ORTHO_WIDTH / 2;
	conf->right = CAMERA_ORTHO_WIDTH / 2;
	conf->top = a * conf->right;
	conf->bottom = a * conf->left;
	conf->near = CAMERA_NEAR;
	conf->far = CAMERA_FAR;
}

void	get_ortho_proj_matrix(t_ortho *cfg, t_mat4 out, double mag)
{
	double	mag_ratio;

	mag_ratio = pow(4, mag);
	out[0][0] = 2. / (mag_ratio * (cfg->right - cfg->left));
	out[0][1] = 0;
	out[0][2] = 0;
	out[0][3] = (cfg->left + cfg->right) / (cfg->left - cfg->right);
	out[1][0] = 0;
	out[1][1] = 2. / (mag_ratio * (cfg->top - cfg->bottom));
	out[1][2] = 0;
	out[1][3] = (cfg->bottom + cfg->top) / (cfg->bottom - cfg->top);
	out[2][0] = 0;
	out[2][1] = 0;
	out[2][2] = 2. / (cfg->far - cfg->near);
	out[2][3] = (cfg->near + cfg->far) / (cfg->near - cfg->far);
	out[3][0] = 0;
	out[3][1] = 0;
	out[3][2] = 0;
	out[3][3] = 1;
}

void	set_proj_orthographic(void)
{
	t_camera	*cam;

	cam = camera();
	cam->type = ORTHOGRAPHIC;
	get_ortho_proj_matrix(get_ortho_config(), cam->proj_mat, cam->mag);
}
