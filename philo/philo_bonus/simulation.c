/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 03:05:02 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/14 03:38:54 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include "process.h"


void	monitor(int n, int *pids)
{
	int	idx;
	int	status;
	int	ended;

	while (1)
	{
		idx = 0;
		ended = 0;
		while (idx < n)
		{
			waitpid(pids[idx], &status, WNOHANG);
			if (WIFEXITED(status))
			{
				if (WEXITSTATUS(status) == 1)
					return ;
				ended++;
			}
			idx++;
		}
		if (ended == n)
			return ;
		usleep(100);
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

void	run_simul(t_conf *cfg)
{
	int	*pids;
	int	idx;

	pids = malloc(sizeof(int) * cfg->n_philo);
	idx = 0;
	while (idx < cfg->n_philo)
	{
		pids[idx] = fork();
		if (pids[idx] == 0)
		{
			process_job(idx + 1, cfg);
			return ;
		}
		idx++;
	}
	monitor(cfg->n_philo, pids);
	kill_processes(cfg->n_philo, pids);
	free(pids);
}
