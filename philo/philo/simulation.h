/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 02:30:20 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/14 14:36:32 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "config.h"
# include "time_util.h"
# include "fork.h"
# include "philo.h"
# include "thread.h"
# include "logger.h"

typedef struct s_simul
{
	t_philo		*philos;
	t_fork		*forks;
	t_arg		*args;
}	t_simul;

void	run_simul(t_conf *cfg);
void	simul_init(t_simul *simul, t_conf *cfg, t_logger *logger);
void	simul_delete(t_simul *simul, int n);

#endif
