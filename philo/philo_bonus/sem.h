/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:19:50 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/14 15:31:52 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEM_H
# define SEM_H

# include <semaphore.h>

typedef struct s_sems
{
	sem_t	*fork;
	sem_t	*running;
}	t_sems;

int		init_semaphore(int n, t_sems *sem);
void	delete_semaphore(t_sems *sem);

#endif
