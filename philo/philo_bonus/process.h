/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 03:08:48 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/14 17:03:11 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include <pthread.h>
# include "config.h"
# include "sem.h"
# include "simulation.h"
# include "logger.h"
# include "time_util.h"

typedef struct s_simul
{
	int				idx;
	t_us			time_eat;
	t_us			time_sleep;
	t_us			last_eat;
	int				remain_eat;
	t_sems			*sem;
	t_logger		*logger;
	pthread_mutex_t	m;
}	t_simul;

void	process_job(int pidx, t_conf *cfg, t_sems *sem, t_logger *logger);

#endif
