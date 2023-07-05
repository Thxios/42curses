/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ortho.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:51:33 by jimlee            #+#    #+#             */
/*   Updated: 2023/06/23 14:37:38 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "camera/camera.h"
#include "camera/ortho.h"
#include "config.h"

t_ortho	*get_ortho_config(void)
{
	static t_ortho	config = (t_ortho){
		CAMERA_LEFT, CAMERA_RIGHT,
		CAMERA_TOP, CAMERA_BOTTOM,
		CAMERA_NEAR, CAMERA_FAR,
		0.
	};

	return (&config);
}

void	get_ortho_proj_matrix(t_ortho *cfg, t_mat4 out)
{
	double	mag_ratio;

	mag_ratio = pow(4, cfg->mag);
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
