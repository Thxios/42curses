/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:16:59 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 19:45:11 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "update.h"
#include "context/context.h"
#include "events/events.h"
#include "object/object.h"
#include "render/render.h"
#include "utils/timestamp.h"

#include <stdio.h>

void	handle_object_translation(t_keys *key, t_obj3d *obj)
{
	static const double	speed = 0.25;
	t_vec	delta;

	delta = (t_vec){0, 0, 0};
	if (key->k_left)
		delta.x -= speed;
	if (key->k_right)
		delta.x += speed;
	if (key->k_up)
		delta.y += speed;
	if (key->k_down)
		delta.y -= speed;
	if (key->k_space)
		delta.z += speed;
	if (key->k_lshift)
		delta.z -= speed;
	translate_object(obj, delta);
}

void	handle_object_rotation(t_keys *key, t_obj3d *obj)
{
	static const double	rot_speed = 0.05;
	double	angle;

	angle = 0;
	if (key->k_w)
		angle += rot_speed;
	if (key->k_s)
		angle -= rot_speed;
	rotate_object(obj, (t_vec){1, 0, 0}, angle);
	angle = 0;
	if (key->k_a)
		angle += rot_speed;
	if (key->k_d)
		angle -= rot_speed;
	rotate_object(obj, (t_vec){0, 1, 0}, angle);
	angle = 0;
	if (key->k_q)
		angle += rot_speed;
	if (key->k_e)
		angle -= rot_speed;
	rotate_object(obj, (t_vec){0, 0, 1}, angle);
}

void	update_frame(t_upd *var)
{
	if (var->obj)
	{
		handle_object_translation(&var->key, var->obj);
		handle_object_rotation(&var->key, var->obj);
	}
}

int	frame(t_upd *var)
{
	static long long	t;
	long long			st;

	st = get_timestamp();
	var->cnt++;
	update_frame(var);
	render_frame(var);
	t += elapsed_usec(st);
	while (elapsed_usec(st) < (1e+6 / FPS))
		usleep(500);
	if (var->cnt >= FPS)
	{
		double fps = FPS * 1e+6 / (double)(t + 1);
		printf("FPS: %.2f\n", fps);
		t = 0;
		print_matrix(var->obj->transform);
		adjust_unit_transform_matrix(var->obj->transform);
		printf("\n");

		var->cnt = 0;
	}
	return (0);
}

void	initialize_mlx_hook(t_upd *upd)
{
	mlx_hook(window(), 17, 0, quit_event, upd);
	mlx_hook(window(), 2, 1 << 0, keydown_event, upd);
	mlx_hook(window(), 3, 1 << 1, keyup_event, upd);
	mlx_hook(window(), 4, 1 << 2, mousedown_event, upd);
	mlx_loop_hook(mlx(), frame, upd);
}
