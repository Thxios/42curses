/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 01:36:13 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/14 01:49:47 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	stop_threads(int n, pthread_t *threads, t_logger *logger, int dead)
{
	int		idx;
	t_us	end_time;

	end_time = get_elapsed_time(logger->start_time);
	pthread_mutex_lock(&logger->mutex);
	logger->running = 0;
	idx = 0;
	while (idx < n)
	{
		pthread_detach(threads[idx]);
		idx++;
	}
	pthread_mutex_unlock(&logger->mutex);
	if (dead > 0)
		printf("%lli %d died\n", end_time / 1000, dead);
}

void	monitor(
	t_conf *cfg, t_philo *philos, t_logger *logger, pthread_t *threads)
{
	int		idx;
	int		eaten;
	t_us	last_eat;

	while (1)
	{
		idx = 0;
		eaten = 0;
		while (idx < cfg->n_philo)
		{
			if (cfg->n_eat > 0
				&& philo_get_num_eaten(&philos[idx]) >= cfg->n_eat)
				eaten++;
			last_eat = philo_get_last_eat(&philos[idx]);
			if (last_eat > 0
				&& get_elapsed_time(last_eat) >= cfg->time_die + 1000)
				return (stop_threads
					(cfg->n_philo, threads, logger, idx + 1));
			idx++;
		}
		if (eaten == cfg->n_philo)
			break ;
		usleep(100);
	}
	stop_threads(cfg->n_philo, threads, logger, 0);
}

void	run_simul(t_conf *cfg)
{
	t_simul		simul;
	t_logger	logger;
	pthread_t	*threads;
	int			idx;

	logger_init(&logger);
	simul_init(&simul, cfg, &logger);
	threads = malloc(sizeof(pthread_t) * cfg->n_philo);
	idx = 0;
	while (idx < cfg->n_philo)
	{
		pthread_create(&threads[idx], 0, thread_job, &simul.args[idx]);
		idx++;
	}
	usleep(1000);
	pthread_mutex_lock(&logger.mutex);
	logger.running = 1;
	logger.start_time = get_timestamp();
	pthread_mutex_unlock(&logger.mutex);
	usleep(1000);
	monitor(cfg, simul.philos, &logger, threads);
	printf("monitor done\n");
	free(threads);
	simul_delete(&simul, cfg->n_philo);
}
