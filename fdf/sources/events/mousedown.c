/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousedown.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:34:08 by jimlee            #+#    #+#             */
/*   Updated: 2023/06/23 14:49:08 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/events.h"
#include "camera/camera.h"

#include <stdio.h>

int	mousedown_event(int button, int x, int y, void *arg)
{
	(void)arg;
	printf("button %d - (%d, %d)\n", button, x, y);
	if (button == BTN_WHEELUP)
	{
		camera_zoom(-1);
	}
	else if (button == BTN_WHEELDOWN)
	{
		camera_zoom(1);
	}
}
