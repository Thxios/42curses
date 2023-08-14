/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 03:05:02 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/14 17:00:48 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <semaphore.h>
#include <sys/wait.h>
#include "sem.h"
#include "process.h"

void	monitor(int n, int *pids)
{
	int	idx;
	int	exited;
	int	status;
	int	n_ended;

	while (1)
	{
		idx = 0;
		n_ended = 0;
		while (idx < n)
		{
			exited = waitpid(pids[idx], &status, WNOHANG);
			if (exited)
			{
				if (WEXITSTATUS(status) == 1)
					return ;
				n_ended++;
			}
			idx++;
		}
		if (n_ended == n)
			return ;
		usleep(1000);
	}
}

void	kill_processes(int n, int *pids)
{
	int	idx;

	idx = 0;
	while (idx < n)
	{
		kill(pids[idx], SIGKILL);
		idx++;
	}
}

void	run_simul_internal(
	t_conf *cfg, int *pids, t_sems *sem, t_logger *logger)
{
	int	idx;

	sem_wait(sem->running);
	logger->start = get_timestamp() + 150 * cfg->n_philo + 100000;
	idx = 0;
	while (idx < cfg->n_philo)
	{
		pids[idx] = fork();
		if (pids[idx] == 0)
		{
			process_job(idx + 1, cfg, sem, logger);
			return ;
		}
		idx++;
	}
	sem_post(sem->running);
	monitor(cfg->n_philo, pids);
	kill_processes(cfg->n_philo, pids);
}

int	run_simul(t_conf *cfg)
{
	int			*pids;
	t_sems		sem;
	t_logger	logger;

	pids = malloc(sizeof(int) * cfg->n_philo);
	if (!pids)
		return (-1);
	if (init_semaphore(cfg->n_philo, &sem) == -1 || logger_init(&logger) == -1)
	{
		free(pids);
		return (-1);
	}
	run_simul_internal(cfg, pids, &sem, &logger);
	free(pids);
	delete_semaphore(&sem);
	logger_delete(&logger);
	return (0);
}
