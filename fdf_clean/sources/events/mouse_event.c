/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:34:08 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/10 10:53:10 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"
#include "events/buttons.h"
#include "camera/camera.h"

void	mousedown_trigger_event(int button, int x, int y, t_upd *upd)
{
	(void)x;
	(void)y;
	(void)upd;
	if (button == BTN_WHEELUP)
	{
		zoom_camera(-1);
	}
	else if (button == BTN_WHEELDOWN)
	{
		zoom_camera(1);
	}
}

int	mousedown_event(int button, int x, int y, t_upd *upd)
{
	(void)upd;
	mousedown_trigger_event(button, x, y, upd);
	return (0);
}
