/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 01:11:01 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/14 15:32:29 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
# define LOGGER_H

# include <semaphore.h>
# include "time_util.h"

typedef struct s_logger
{
	sem_t	*sem;
	t_us	start;
}	t_logger;

int		logger_init(t_logger *logger);
void	logger_delete(t_logger *logger);
void	logger_print(t_logger *logger, t_us timestamp, int p_idx, char *msg);

#endif
