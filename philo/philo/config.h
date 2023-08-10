/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:07:25 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/10 22:51:03 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "time_util.h"

typedef struct s_conf
{
	int		n_philo;
	t_us	time_eat;
	t_us	time_sleep;
	t_us	time_die;
	int		n_eat;
}	t_conf;

#endif
