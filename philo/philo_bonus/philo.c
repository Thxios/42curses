/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 01:33:09 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/14 17:07:55 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_us	philo_eat(t_simul *p, t_logger *logger, t_us time_eat)
{
	t_us	eat_start;

	sem_wait(p->sem->fork);
	pthread_mutex_lock(&p->m);
	logger_print(logger, get_timestamp(), p->idx, "has taken a fork");
	pthread_mutex_unlock(&p->m);
	sem_wait(p->sem->fork);
	eat_start = get_timestamp();
	pthread_mutex_lock(&p->m);
	p->last_eat = eat_start;
	logger_print(logger, eat_start, p->idx, "has taken a fork");
	logger_print(logger, eat_start, p->idx, "is eating");
	pthread_mutex_unlock(&p->m);
	wait_from_until(eat_start, time_eat);
	sem_post(p->sem->fork);
	sem_post(p->sem->fork);
	pthread_mutex_lock(&p->m);
	pthread_mutex_unlock(&p->m);
	return (eat_start + time_eat);
}

t_us	philo_sleep(t_simul *p, t_logger *logger, t_us time_sleep, t_us start)
{
	pthread_mutex_lock(&p->m);
	logger_print(logger, start, p->idx, "is sleeping");
	pthread_mutex_unlock(&p->m);
	wait_from_until(start, time_sleep);
	return (start + time_sleep);
}

void	philo_think(t_simul *p, t_logger *logger, t_us start)
{
	pthread_mutex_lock(&p->m);
	logger_print(logger, start, p->idx, "is thinking");
	pthread_mutex_unlock(&p->m);
}
