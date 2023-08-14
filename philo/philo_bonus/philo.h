/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:19:51 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/14 16:23:34 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "process.h"
# include "logger.h"
# include "time_util.h"

t_us	philo_eat(t_simul *p, t_logger *logger, t_us time_eat);
t_us	philo_sleep(t_simul *p, t_logger *logger, t_us time_sleep, t_us start);
void	philo_think(t_simul *p, t_logger *logger, t_us start);

#endif
