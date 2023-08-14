/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 02:19:57 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/14 14:36:56 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include <stdlib.h>

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
		ret[idx].time_eat = cfg->time_eat;
		ret[idx].time_sleep = cfg->time_sleep;
		idx++;
	}
	return (ret);
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
		idx++;
	}
	free(simul->forks);
	free(simul->philos);
	free(simul->args);
}
