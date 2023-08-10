/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 01:13:15 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/10 23:11:03 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "logger.h"

void	logger_init(t_logger *logger)
{
	pthread_mutex_init(&logger->mutex, 0);
	logger->start_time = -1;
	logger->running = 0;
}

void	logger_delete(t_logger *logger)
{
	pthread_mutex_destroy(&logger->mutex);
}

void	logger_print(t_logger *logger, t_us timestamp, int philo_idx, char *msg)
{
	pthread_mutex_lock(&logger->mutex);
	if (logger->running)
		printf("%lli %d %s\n",
			(timestamp - logger->start_time) / 1000, philo_idx, msg);
	pthread_mutex_unlock(&logger->mutex);
}
