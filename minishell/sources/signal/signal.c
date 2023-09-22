/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:32:09 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/15 22:58:59 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"
#include "command/execute.h"
#include "signal/signal_utils.h"
#include "env/env.h"

void	sigint_run_handler(int signo)
{
	(void)signo;
	ft_putstr_fd("\n", STDOUT_FILENO);
}

void	sigint_enter_handler(int signo)
{
	(void)signo;
	ft_putstr_fd("\n", STDOUT_FILENO);
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
	g_last_exit_code = 1;
}

void	sigquit_handler(int signo)
{
	(void)signo;
	ft_putstr_fd("Quit: 3\n", STDERR_FILENO);
}
