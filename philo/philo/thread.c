/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 02:12:37 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/18 14:06:02 by jimlee           ###   ########.fr       */
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
		usleep(100);
		started = logger_get_running(logger);
	}
}

void	start_cycle(t_philo *p, t_logger *logger, t_arg *arg)
{
	t_us	timestamp;

	while (logger_get_running(logger))
	{
		timestamp = philo_eat(p, logger, arg->time_eat);
		timestamp = philo_sleep(p, logger, arg->time_sleep, timestamp);
		philo_think(p, logger, timestamp);
	}
}

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
		usleep(arg->time_eat / 5);
	start_cycle(p, logger, arg);
	return (0);
}
