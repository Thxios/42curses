/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:25:08 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/17 19:28:06 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include "philo.h"

void	*thread_job(void *arg_vptr)
{
	t_simul		*arg;
	t_logger	*logger;

	arg = arg_vptr;
	logger = arg->logger;
	pthread_mutex_lock(&arg->m);
	pthread_mutex_unlock(&arg->m);
	philo_think(arg, logger, logger->start);
	if (arg->idx % 2 == 1)
		usleep(arg->time_eat / 5);
	while (arg->remain_eat)
	{
		philo_think(arg, logger,
			philo_sleep(arg, logger, arg->time_sleep,
				philo_eat(arg, logger, arg->time_eat)));
		if (arg->remain_eat > 0)
			arg->remain_eat--;
	}
	exit(0);
}

void	monitor_one(t_simul *arg, t_conf *cfg, t_logger *logger)
{
	t_us	last_eat;

	while (1)
	{
		pthread_mutex_lock(&arg->m);
		last_eat = arg->last_eat;
		pthread_mutex_unlock(&arg->m);
		if (get_elapsed_time(last_eat) > cfg->time_die + 1000)
		{
			pthread_mutex_lock(&arg->m);
			sem_wait(logger->sem);
			printf("%lli %d died\n",
				get_elapsed_time(logger->start) / 1000, arg->idx);
			exit(1);
		}
		usleep(1000);
	}
}

void	process_job(int pidx, t_conf *cfg, t_sems *sem, t_logger *logger)
{
	pthread_t	thread;
	t_simul		simul;

	simul.idx = pidx;
	simul.time_eat = cfg->time_eat;
	simul.time_sleep = cfg->time_sleep;
	simul.remain_eat = cfg->n_eat;
	if (cfg->n_eat == 0)
		simul.remain_eat = -1;
	simul.sem = sem;
	simul.logger = logger;
	pthread_mutex_init(&simul.m, 0);
	pthread_mutex_lock(&simul.m);
	pthread_create(&thread, 0, thread_job, &simul);
	pthread_detach(thread);
	sem_wait(sem->running);
	sem_post(sem->running);
	while (get_timestamp() < simul.logger->start - 15)
		usleep(10);
	simul.last_eat = simul.logger->start;
	pthread_mutex_unlock(&simul.m);
	monitor_one(&simul, cfg, logger);
}
