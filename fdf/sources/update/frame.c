/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:34:18 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/21 16:25:08 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "update/frame.h"

#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int	update_frame(t_upd *var)
{
	(void)var;
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
	render_frame(&var->render);
	while (get_time_elapsed(&st) < (1e+6 / FPS))
		usleep(500);
	if (var->cnt >= FPS)
	{
		// printf("st(s=%li, us=%li)\n", st.tv_sec, st.tv_usec);
		// printf("ed(s=%li, us=%li)\n", ed.tv_sec, ed.tv_usec);
		// printf("time %li usec, cnt %d\n", timediff, var->cnt);
		printf("time %li\n", get_time_elapsed(&st));

		var->cnt = 0;
	}
	return (0);
}
