/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:21:54 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/15 03:22:36 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sem.h"

#include <fcntl.h>

sem_t	*make_sem(int n, char *name)
{
	sem_t	*sem_fd;

	sem_unlink(name);
	sem_fd = sem_open(name, O_CREAT | O_EXCL, 0644, n);
	if (sem_fd == SEM_FAILED)
		return (0);
	return (sem_fd);
}

int	init_semaphore(int n, t_sems *sem)
{
	sem->fork = make_sem(n, "fork");
	sem->running = make_sem(1, "running");
	if (!sem->fork || !sem->running)
	{
		delete_semaphore(sem);
		return (-1);
	}
	return (0);
}

void	delete_semaphore(t_sems *sem)
{
	if (sem->fork)
	{
		sem_close(sem->fork);
		sem_unlink("fork");
	}
	if (sem->running)
	{
		sem_close(sem->running);
		sem_unlink("running");
	}
}
