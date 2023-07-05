/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:34:18 by jimlee            #+#    #+#             */
/*   Updated: 2023/06/23 15:04:04 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "update/frame.h"
#include "object/object.h"
#include "render/render.h"

#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

void	translate_object(t_keys *key, t_obj3d *obj)
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
	translate(obj, delta);
}

void	rotate_object(t_keys *key, t_obj3d *obj)
{
	static const double	rot_speed = 0.05;
	double	angle;

	angle = 0;
	if (key->k_w)
		angle += rot_speed;
	if (key->k_s)
		angle -= rot_speed;
	rotate(obj, (t_vec){1, 0, 0}, angle);
	angle = 0;
	if (key->k_a)
		angle += rot_speed;
	if (key->k_d)
		angle -= rot_speed;
	rotate(obj, (t_vec){0, 1, 0}, angle);
	angle = 0;
	if (key->k_q)
		angle += rot_speed;
	if (key->k_e)
		angle -= rot_speed;
	rotate(obj, (t_vec){0, 0, 1}, angle);
}

void	handle_transform(t_keys *key, t_obj3d *obj)
{
	translate_object(key, obj);
	rotate_object(key, obj);
	// if (key->)
}

int	update_frame(t_upd *var)
{
	(void)var;

	if (var->obj)
	{
		handle_transform(&var->key, var->obj);
		compute_camera_proj(var->obj, camera());
	}

	return (0);
}

long	get_time_elapsed(struct timeval *st)
{
	struct timeval	ed;

	gettimeofday(&ed, NULL);
	return (1e+6 * (ed.tv_sec - st->tv_sec) + (ed.tv_usec - st->tv_usec));
}

int	frame(t_upd *var)
{
	struct timeval	st;

	gettimeofday(&st, NULL);
	// timespec_get
	var->cnt++;
	update_frame(var);
	render_frame(var);
	while (get_time_elapsed(&st) < (1e+6 / FPS))
		usleep(500);
	if (var->cnt >= FPS)
	{
		// printf("st(s=%li, us=%li)\n", st.tv_sec, st.tv_usec);
		// printf("ed(s=%li, us=%li)\n", ed.tv_sec, ed.tv_usec);
		// printf("time %li usec, cnt %d\n", timediff, var->cnt);
		// printf("time %li\n", get_time_elapsed(&st));
		// print_matrix(var->obj->transform);
		print_vec4(var->obj->v[5].scr_p);
		printf("\n");

		var->cnt = 0;
	}
	return (0);
}