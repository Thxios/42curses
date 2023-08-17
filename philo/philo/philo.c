/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 01:33:09 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/17 19:10:13 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_philo *p, int idx, t_fork *fork1, t_fork *fork2)
{
	p->idx = idx;
	p->num_eaten = 0;
	p->first = fork1;
	p->second = fork2;
	if (fork1->priority > fork2->priority)
	{
		p->first = fork1;
		p->second = fork2;
	}
	else
	{
		p->first = fork2;
		p->second = fork1;
	}
	p->last_eat = -1;
	pthread_mutex_init(&p->mutex, 0);
}

void	philo_delete(t_philo *p)
{
	pthread_mutex_destroy(&p->mutex);
}

t_us	philo_eat(t_philo *p, t_logger *logger, t_us time_eat)
{
	t_us	eat_start;

	fork_lock(p->first);
	logger_print(logger, get_timestamp(), p->idx, "has taken a fork");
	fork_lock(p->second);
	eat_start = get_timestamp();
	philo_set_last_eat(p, eat_start);
	logger_print(logger, eat_start, p->idx, "has taken a fork");
	logger_print(logger, eat_start, p->idx, "is eating");
	wait_from_until(eat_start, time_eat);
	fork_unlock(p->first);
	fork_unlock(p->second);
	philo_increase_num_eaten(p);
	return (eat_start + time_eat);
}

t_us	philo_sleep(t_philo *p, t_logger *logger, t_us time_sleep, t_us start)
{
	logger_print(logger, start, p->idx, "is sleeping");
	wait_from_until(start, time_sleep);
	return (start + time_sleep);
}

void	philo_think(t_philo *p, t_logger *logger, t_us start)
{
	logger_print(logger, start, p->idx, "is thinking");
}
