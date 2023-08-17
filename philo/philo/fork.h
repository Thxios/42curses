/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 04:19:49 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/17 19:15:44 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include <pthread.h>

typedef struct s_fork
{
	int				priority;
	pthread_mutex_t	mutex;
}	t_fork;

void	fork_init(t_fork *fk, int priority);
void	fork_delete(t_fork *fk);
void	fork_lock(t_fork *fk);
void	fork_unlock(t_fork *fk);

#endif
