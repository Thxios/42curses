/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:05:32 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/15 03:22:42 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logger.h"
#include <stdio.h>
#include <semaphore.h>

#include <fcntl.h>

int	logger_init(t_logger *logger)
{
	logger->start = -1;
	sem_unlink("logger");
	logger->sem = sem_open("logger", O_CREAT | O_EXCL, 0644, 1);
	if (logger->sem == SEM_FAILED)
		return (-1);
	return (0);
}

void	logger_delete(t_logger *logger)
{
	sem_close(logger->sem);
	sem_unlink("logger");
}

void	logger_print(t_logger *logger, t_us timestamp, int p_idx, char *msg)
{
	sem_wait(logger->sem);
	printf("%lli %d %s\n",
		(timestamp - logger->start) / 1000, p_idx, msg);
	sem_post(logger->sem);
}
