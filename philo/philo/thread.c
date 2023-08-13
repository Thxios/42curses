/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 02:12:37 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/14 01:43:02 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"
#include <pthread.h>
#include <unistd.h>

void	wait_for_start(t_logger *logger)
{
	int	started;

	started = 0;
	while (!started)
	{
		usleep(10);
		pthread_mutex_lock(&logger->mutex);
		started = logger->running;
		pthread_mutex_unlock(&logger->mutex);
	}
}
#include <stdio.h>

void	*thread_job(void *arg_vptr)
{
	t_arg		*arg;
	t_philo		*p;
	t_logger	*logger;

	arg = arg_vptr;
	p = arg->philo;
	logger = arg->logger;
	wait_for_start(logger);
	philo_set_last_eat(p, logger->start_time);
	philo_think(p, logger, logger->start_time);
	if (p->idx % 2 == 0)
		usleep(arg->time_eat / 10);
	// while (1)
	while (logger->running)
	{
		philo_think(p, logger,
			philo_sleep(p, logger, arg->time_sleep,
				philo_eat(p, logger, arg->time_eat)));
	}
	printf("%d done\n", p->idx);
	return (0);
}
