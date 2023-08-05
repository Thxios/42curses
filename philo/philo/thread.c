/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 02:12:37 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/16 12:16:03 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

void	*thread_job(void *arg_vptr)
{
	t_arg		*arg;
	t_philo		*p;
	t_logger	*logger;

	arg = arg_vptr;
	p = arg->philo;
	logger = arg->logger;
	philo_set_last_eat(p, logger->start_time);
	philo_think(p, logger);
	// while (1)
    if (p->idx % 2 == 0) {
        usleep(arg->time_eat / 10);
    }
	while (philo_get_num_eaten(p) < 7)
	{
		philo_eat(p, logger, arg->time_eat);
		philo_sleep(p, logger, arg->time_sleep);
		philo_think(p, logger);
	}
	// logger_print(logger, get_timestamp(), p->idx, "done");
	return (0);
}
