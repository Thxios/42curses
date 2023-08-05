/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:04:42 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 19:07:26 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"
#include "events/events.h"
#include "camera/camera.h"

#include <stdio.h>

void	set_key_pressed(int keycode, t_keys *key, int pressed)
{
	if (keycode == KEY_Q)
		key->k_q = pressed;
	else if (keycode == KEY_W)
		key->k_w = pressed;
	else if (keycode == KEY_E)
		key->k_e = pressed;
	else if (keycode == KEY_A)
		key->k_a = pressed;
	else if (keycode == KEY_S)
		key->k_s = pressed;
	else if (keycode == KEY_D)
		key->k_d = pressed;
	else if (keycode == KEY_UP)
		key->k_up = pressed;
	else if (keycode == KEY_DOWN)
		key->k_down = pressed;
	else if (keycode == KEY_LEFT)
		key->k_left = pressed;
	else if (keycode == KEY_RIGHT)
		key->k_right = pressed;
	else if (keycode == KEY_SPACE)
		key->k_space = pressed;
	else if (keycode == KEY_LSHIFT)
		key->k_lshift = pressed;
}

void	keydown_trigger_event(int keycode, t_upd *upd)
{
	if (keycode == KEY_ESCAPE)
		quit_event(upd);
	else if (keycode == KEY_TAB)
		toggle_camera_type();
}

int	keydown_event(int keycode, t_upd *upd)
{
	// printf("keydown - code %d\n", keycode);
	keydown_trigger_event(keycode, upd);
	set_key_pressed(keycode, &upd->key, 1);
	return (0);
}

int	keyup_event(int keycode, t_upd *upd)
{
	// printf("keyup - code %d\n", keycode);
	set_key_pressed(keycode, &upd->key, 0);
	return (0);
}
