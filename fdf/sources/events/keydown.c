/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keydown.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:04:42 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/17 16:16:00 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/events.h"

#include <stdio.h>

int	keydown_event(int keycode, t_keys *key)
{
	printf("keydown - code %d\n", keycode);
	if (keycode == KEY_ESCAPE)
		quit_event();
	else if (keycode == KEY_Q)
		key->k_q = 1;
	else if (keycode == KEY_W)
		key->k_w = 1;
	else if (keycode == KEY_E)
		key->k_e = 1;
	else if (keycode == KEY_A)
		key->k_a = 1;
	else if (keycode == KEY_S)
		key->k_s = 1;
	else if (keycode == KEY_D)
		key->k_d = 1;
	else if (keycode == KEY_UP)
		key->k_up = 1;
	else if (keycode == KEY_DOWN)
		key->k_down = 1;
	else if (keycode == KEY_LEFT)
		key->k_left = 1;
	else if (keycode == KEY_RIGHT)
		key->k_right = 1;
	return (0);
}

int	keyup_event(int keycode, t_keys *key)
{
	printf("keyup - code %d\n", keycode);
	if (keycode == KEY_ESCAPE)
		quit_event();
	else if (keycode == KEY_Q)
		key->k_q = 0;
	else if (keycode == KEY_W)
		key->k_w = 0;
	else if (keycode == KEY_E)
		key->k_e = 0;
	else if (keycode == KEY_A)
		key->k_a = 0;
	else if (keycode == KEY_S)
		key->k_s = 0;
	else if (keycode == KEY_D)
		key->k_d = 0;
	else if (keycode == KEY_UP)
		key->k_up = 0;
	else if (keycode == KEY_DOWN)
		key->k_down = 0;
	else if (keycode == KEY_LEFT)
		key->k_left = 0;
	else if (keycode == KEY_RIGHT)
		key->k_right = 0;
	return (0);
}
