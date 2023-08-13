/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 02:09:31 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/13 16:26:09 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include "philo.h"
# include "logger.h"
# include "time_util.h"

typedef struct s_arg
{
	t_philo		*philo;
	t_logger	*logger;
	t_us		time_eat;
	t_us		time_sleep;
}	t_arg;

void	*thread_job(void *arg_vptr);

#endif
