/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:34:08 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/07 16:16:54 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/events.h"
#include "camera/camera.h"

#include <stdio.h>

void	mousedown_trigger_event(int button, int x, int y)
{
	if (button == BTN_WHEELUP)
	{
		camera_zoom(-1);
	}
	else if (button == BTN_WHEELDOWN)
	{
		camera_zoom(1);
	}
}

int	mousedown_event(int button, int x, int y, void *arg)
{
	(void)arg;
	// printf("button %d - (%d, %d)\n", button, x, y);
	mousedown_trigger_event(button, x, y);
}
