/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 02:19:57 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/16 12:17:19 by jimlee           ###   ########.fr       */
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
		// if (idx % 2 == 1)
			fork_init(&ret[idx], idx + 1);
		// else
			// fork_init(&ret[idx], -(idx + 1));
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

t_arg	*new_args(int n, t_philo *philos, t_logger *logger, t_us time_eat, t_us time_sleep)
{
	int		idx;
	t_arg	*ret;

	ret = malloc(sizeof(t_arg) * n);
	idx = 0;
	while (idx < n)
	{
		ret[idx].philo = &philos[idx];
		ret[idx].logger = logger;
		ret[idx].time_eat = time_eat;
		ret[idx].time_sleep = time_sleep;
		idx++;
	}
	return (ret);
}

void	stop_philo_threads(int n, pthread_t *threads, t_logger *logger, int locked)
{
	int	idx;

	idx = 0;
	if (!locked)
		pthread_mutex_lock(&logger->mutex);
	while (idx < n)
	{
		pthread_detach(threads[idx]);
		idx++;
	}
	if (!locked)
		pthread_mutex_unlock(&logger->mutex);
}

void	monitor(int n, t_philo *philos, int num_eat, t_us time_die,
t_logger *logger, pthread_t *threads)
{
	int	idx;
	int	eaten;

	while (1)
	{
		idx = 0;
		eaten = 0;
		while (idx < n)
		{
			if (philo_get_num_eaten(&philos[idx]) >= num_eat)
				eaten++;
			if (get_elapsed_time(philo_get_last_eat(&philos[idx])) >= time_die)
			{
				pthread_mutex_lock(&logger->mutex);
				printf("%lli %d died\n", 
					get_elapsed_time(logger->start_time) / 1000, idx);
				stop_philo_threads(n, threads, logger, 1);
				pthread_mutex_unlock(&logger->mutex);
				return ;
			}
			idx++;
		}
		if (eaten == n)
			break ;
		usleep(100);
	}
	stop_philo_threads(n, threads, logger, 0);
}

void	run(int n)
{
	t_logger	logger;
	t_philo		*philos;
	t_fork		*forks;
	t_arg		*args;
	pthread_t	*threads;

	forks = new_forks(n);
	philos = new_philos(n, forks);
	logger_init(&logger);
	args = new_args(n, philos, &logger, 200000, 100000);
	threads = malloc(sizeof(pthread_t) * n);
	logger.start_time = get_timestamp();
	for (int i = 0; i < n; i++)
	{
		philos[i].last_eat = logger.start_time;
		pthread_create(&threads[i], 0, thread_job, &args[i]);
	}
	// for (int i = 0; i < n; i += 2)
	// 	pthread_create(&threads[i], 0, thread_job, &args[i]);
	// usleep(100);
	// for (int i = 1; i < n; i += 2)
	// 	pthread_create(&threads[i], 0, thread_job, &args[i]);
	// if (n % 2 == 1)
	// 	pthread_create(&threads[n - 1], 0, thread_job, &args[n - 1]);
	// for (int i = 0; i < n; i++)
	// {
	// 	pthread_join(threads[i], 0);
	// }
	monitor(n, philos, 5, 601000, &logger, threads);
}

int main() {
	run(6);
}
