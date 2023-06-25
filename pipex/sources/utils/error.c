/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:55:20 by jimlee            #+#    #+#             */
/*   Updated: 2023/06/26 01:16:25 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/error.h"
#include "libft/libft.h"
#include "utils/info.h"

void	fatal_error(const char *message)
{
	ft_putstr_fd(info()->exe, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	perror(message);
	exit(1);
}

void	command_find_error(const char *message)
{
	ft_putstr_fd(info()->exe, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	perror(message);
	exit(127);
}

void	command_permission_error(const char *message)
{
	ft_putstr_fd(info()->exe, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	perror(message);
	exit(126);
}

void	command_not_found_error(const char *command)
{
	ft_putstr_fd(info()->exe, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd((char *)command, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(127);
}

void	parse_eof_error(void)
{
	ft_putstr_fd("syntax error: unexpected end of file\n", STDERR_FILENO);
	exit(1);
}
