/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 02:19:57 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/10 23:13:01 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

t_fork	*new_forks(int n)
{
	int		idx;
	t_fork	*ret;

	ret = malloc(sizeof(t_fork) * n);
	idx = 0;
	while (idx < n)
	{
		fork_init(&ret[idx]);
		idx++;
	}
	return (ret);
}

t_philo	*new_philos(int n, t_fork *forks)
{
	int		idx;
	t_philo	*ret;

	ret = malloc(sizeof(t_philo) * n);
	idx = 0;
	while (idx < n)
	{
		philo_init(&ret[idx], idx + 1, &forks[idx], &forks[(idx + 1) % n]);
		idx++;
	}
	return (ret);
}

t_arg	*new_args(t_conf *cfg, t_philo *philos, t_logger *logger)
{
	int		idx;
	t_arg	*ret;

	ret = malloc(sizeof(t_arg) * cfg->n_philo);
	idx = 0;
	while (idx < cfg->n_philo)
	{
		ret[idx].philo = &philos[idx];
		ret[idx].logger = logger;
		ret[idx].time_eat = cfg->time_die;
		ret[idx].time_sleep = cfg->time_sleep;
		idx++;
	}
	return (ret);
}

void	stop_philo_threads(
	int n, pthread_t *threads, t_logger *logger, int dead)
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
				return (stop_philo_threads
					(cfg->n_philo, threads, logger, idx + 1));
			idx++;
		}
		if (eaten == cfg->n_philo)
			break ;
		usleep(100);
	}
	stop_philo_threads(cfg->n_philo, threads, logger, 0);
}

void	simul_init(t_simul *simul, t_conf *cfg, t_logger *logger)
{
	simul->forks = new_forks(cfg->n_philo);
	simul->philos = new_philos(cfg->n_philo, simul->forks);
	simul->args = new_args(cfg, simul->philos, logger);
}

void	simul_delete(t_simul *simul, int n)
{
	int	idx;

	idx = 0;
	while (idx < n)
	{
		fork_delete(&simul->forks[idx]);
		philo_delete(&simul->philos[idx]);
	}
	free(simul->forks);
	free(simul->philos);
	free(simul->args);
}

void	run(t_conf *cfg)
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
	free(threads);
	simul_delete(&simul, cfg->n_philo);
}

int	main(int argc, char *argv[])
{
	t_conf	cfg;

	cfg.n_philo = 19;
	cfg.time_eat = 200 * 1000;
	cfg.time_sleep = 100 * 1000;
	cfg.time_die = 600 * 1000;
	cfg.n_eat = 10;
	run(&cfg);
}
