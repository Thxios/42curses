/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 02:17:10 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/17 19:15:40 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork.h"

void	fork_init(t_fork *fk, int priority)
{
	fk->priority = priority;
	pthread_mutex_init(&fk->mutex, 0);
}

void	fork_delete(t_fork *fk)
{
	pthread_mutex_destroy(&fk->mutex);
}

void	fork_lock(t_fork *fk)
{
	pthread_mutex_lock(&fk->mutex);
}

void	fork_unlock(t_fork *fk)
{
	pthread_mutex_unlock(&fk->mutex);
}
