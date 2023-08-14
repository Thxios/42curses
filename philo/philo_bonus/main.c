/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:57:28 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/14 17:09:49 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "config.h"
#include "utils.h"
#include "simulation.h"

int	parse_arg(t_conf *cfg, int argc, char *argv[])
{
	if ((argc != 5) && (argc != 6))
		return (-1);
	cfg->n_philo = ft_atoi(argv[1]);
	cfg->time_die = ft_atoi(argv[2]) * 1000;
	cfg->time_eat = ft_atoi(argv[3]) * 1000;
	cfg->time_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		cfg->n_eat = ft_atoi(argv[5]);
	else
		cfg->n_eat = 0;
	if ((cfg->n_philo < 2) || (cfg->time_die < 0) || (cfg->time_eat < 0)
		|| (cfg->time_sleep < 0) || (cfg->n_eat < 0))
		return (-1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_conf	cfg;

	if (parse_arg(&cfg, argc, argv) == -1)
	{
		printf("invalid arguments\n");
		return (1);
	}
	if (run_simul(&cfg) == -1)
	{
		printf("fatal error\n");
		return (1);
	}
	return (0);
}
