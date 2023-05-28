/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:22:57 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/29 01:49:27 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "utils/info.h"
#include "command/command.h"
#include "parser/parser.h"
#include "pipe/io.h"
#include "utils/error.h"

int	open_in_file(char *file, int flag)
{
	int	fd;

	if (flag & IN_HERE_DOC)
		fd = open_here_doc(file);
	else
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			fatal_error(file);
	}
	return (fd);
}

int	open_out_file(char *file, int flag)
{
	int	fd;

	if (flag & OUT_APPEND)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		fatal_error(file);
	return (fd);
}

void	execute_single_pipe(char *cmd_str, t_io *io)
{
	t_cmd	*cmd;

	if (io->in_file)
	{
		if (io->in_flag & IN_HERE_DOC)
			io->in_fd = open_here_doc(io->in_file);
		else
			io->in_fd = open_in_file(io->in_file, io->in_flag);
	}
	if (io->out_file)
		io->out_fd = open_out_file(io->out_file, io->out_flag);
	dup2(io->in_fd, STDIN_FILENO);
	dup2(io->out_fd, STDOUT_FILENO);
	cmd = parse_commnad(cmd_str);
	if (execve(cmd->exec_path, cmd->argv, info()->envp) == -1)
		fatal_error(cmd->argv[0]);
	exit(0);
}
