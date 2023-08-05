/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 01:33:09 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/16 11:57:11 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	philo_init(t_philo *p, int idx, t_fork *fork1, t_fork *fork2)
{
	p->idx = idx;
	p->num_eaten = 0;
	// if (fork1->priority > fork2->priority)
	// {
		p->first = fork1;
		p->second = fork2;
	// }
	// else
	// {
	// 	p->first = fork2;
	// 	p->second = fork1;
	// }
	printf("philo %d: fork1: %d, fork2: %d\n", idx, fork1->priority, fork2->priority);
	p->last_eat = 0;
	pthread_mutex_init(&p->mutex, 0);
}

void	philo_delete(t_philo *p)
{
	pthread_mutex_destroy(&p->mutex);
}

void	philo_eat(t_philo *p, t_logger *logger, t_us time_eat)
{
	t_us	eat_start;

	fork_lock(p->first);
	logger_print(logger, get_timestamp(), p->idx, "has taken a fork");
	fork_lock(p->second);
	eat_start = get_timestamp();
	logger_print(logger, eat_start, p->idx, "has taken a fork");
	logger_print(logger, eat_start, p->idx, "is eating");
	philo_set_last_eat(p, eat_start);
	wait_from_until(eat_start, time_eat);
	fork_unlock(p->first);
	fork_unlock(p->second);
	philo_increase_num_eaten(p);
}

void	philo_sleep(t_philo *p, t_logger *logger, t_us time_eat)
{
	t_us	sleep_start;

	sleep_start = get_timestamp();
	logger_print(logger, sleep_start, p->idx, "is sleeping");
	wait_from_until(sleep_start, time_eat);
}

void	philo_think(t_philo *p, t_logger *logger)
{
	logger_print(logger, get_timestamp(), p->idx, "is thinking");
}
