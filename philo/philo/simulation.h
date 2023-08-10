/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 02:30:20 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/10 22:29:23 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include "time_util.h"
# include "logger.h"
# include "fork.h"
# include "philo.h"
# include "thread.h"
# include "config.h"

typedef struct s_simul
{
	t_philo		*philos;
	t_fork		*forks;
	t_arg		*args;
}	t_simul;

#endif
