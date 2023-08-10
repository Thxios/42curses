/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:18:38 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/10 20:30:14 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include "time_util.h"
# include "fork.h"
# include "logger.h"

typedef struct s_philo
{
	int				idx;
	int				num_eaten;
	t_us			last_eat;
	t_fork			*first;
	t_fork			*second;
	pthread_mutex_t	mutex;
}	t_philo;

void	philo_init(t_philo *p, int idx, t_fork *fork1, t_fork *fork2);
void	philo_delete(t_philo *p);

t_us	philo_get_last_eat(t_philo *p);
void	philo_set_last_eat(t_philo *p, t_us last_eat);
int		philo_get_num_eaten(t_philo *p);
void	philo_increase_num_eaten(t_philo *p);

t_us	philo_eat(t_philo *p, t_logger *logger, t_us time_eat);
t_us	philo_sleep(t_philo *p, t_logger *logger, t_us time_sleep, t_us start);
void	philo_think(t_philo *p, t_logger *logger, t_us start);

#endif
