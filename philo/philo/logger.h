/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 01:11:01 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/12 01:55:06 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
# define LOGGER_H

# include <pthread.h>
# include "time_util.h"

typedef struct s_logger
{
	t_us			start_time;
	pthread_mutex_t	mutex;
}	t_logger;

void	logger_init(t_logger *logger);
void	logger_delete(t_logger *logger);
void	logger_print(t_logger *logger, t_us timestamp, int philo_idx, char *msg);

#endif
