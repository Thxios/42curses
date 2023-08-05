/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:16:59 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/10 10:27:33 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
#include "config.h"
#include "update.h"
#include "context/context.h"
#include "events/events.h"
#include "object/object.h"
#include "render/render.h"
#include "utils/timestamp.h"

void	handle_object_translation(t_keys *key, t_obj3d *obj)
{
	t_vec	delta;

	delta = (t_vec){0, 0, 0};
	if (key->k_left)
		delta.x -= OBJ_TRANSLATE_SPEED;
	if (key->k_right)
		delta.x += OBJ_TRANSLATE_SPEED;
	if (key->k_up)
		delta.y += OBJ_TRANSLATE_SPEED;
	if (key->k_down)
		delta.y -= OBJ_TRANSLATE_SPEED;
	if (key->k_space)
		delta.z += OBJ_TRANSLATE_SPEED;
	if (key->k_lshift)
		delta.z -= OBJ_TRANSLATE_SPEED;
	translate_object(obj, delta);
}

void	handle_object_rotation(t_keys *key, t_obj3d *obj)
{
	double	angle;

	angle = 0;
	if (key->k_w)
		angle += OBJ_ROTATE_SPEED;
	if (key->k_s)
		angle -= OBJ_ROTATE_SPEED;
	rotate_object(obj, (t_vec){1, 0, 0}, angle);
	angle = 0;
	if (key->k_a)
		angle += OBJ_ROTATE_SPEED;
	if (key->k_d)
		angle -= OBJ_ROTATE_SPEED;
	rotate_object(obj, (t_vec){0, 1, 0}, angle);
	angle = 0;
	if (key->k_q)
		angle += OBJ_ROTATE_SPEED;
	if (key->k_e)
		angle -= OBJ_ROTATE_SPEED;
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
		t = 0;
		adjust_unit_transform_matrix(var->obj->transform);
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
