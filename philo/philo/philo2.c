/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 01:33:09 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/12 21:49:39 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_us	philo_get_last_eat(t_philo *p)
{
	t_us	last_eat;

	pthread_mutex_lock(&p->mutex);
	last_eat = p->last_eat;
	pthread_mutex_unlock(&p->mutex);
	return (last_eat);
}

void	philo_set_last_eat(t_philo *p, t_us last_eat)
{
	pthread_mutex_lock(&p->mutex);
	p->last_eat = last_eat;
	pthread_mutex_unlock(&p->mutex);
}

int	philo_get_num_eaten(t_philo *p)
{
	int	num_eaten;

	pthread_mutex_lock(&p->mutex);
	num_eaten = p->num_eaten;
	pthread_mutex_unlock(&p->mutex);
	return (num_eaten);
}

void	philo_increase_num_eaten(t_philo *p)
{
	pthread_mutex_lock(&p->mutex);
	p->num_eaten++;
	pthread_mutex_unlock(&p->mutex);
}
