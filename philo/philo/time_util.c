/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:23:22 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/10 22:19:49 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/time.h>
#include "time_util.h"

t_us	get_timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, 0);
	return ((long long)1000000 * t.tv_sec + t.tv_usec);
}

t_us	get_elapsed_time(t_us start)
{
	return (get_timestamp() - start);
}

void	wait_from_until(t_us start, t_us duration)
{
	while (get_elapsed_time(start) < duration - 15)
		usleep(10);
}
