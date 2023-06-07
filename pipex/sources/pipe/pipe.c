/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:22:57 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/29 01:10:15 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "utils/info.h"
#include "command/command.h"
#include "parser/parser.h"
#include "pipe/io.h"
#include "utils/error.h"

#include <stdio.h>

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

	// printf("child(%d): cmd \"%s\", in \"%s\" flg %d, out \"%s\" flg %d\n",
	// 	getpid(), cmd_str, io->in_file,io->in_flag,io->out_file, io->out_flag);
	if (io->in_file)
	{
		if (io->in_flag & IN_HERE_DOC)
			io->in_fd = open_here_doc(io->in_file);
		else
			io->in_fd = open_in_file(io->in_file, io->in_flag);
	}
	// printf("child(%d): infile done\n", getpid());
	if (io->out_file)
		io->out_fd = open_out_file(io->out_file, io->out_flag);
	// printf("child(%d): outfile done\n", getpid());
	// printf("child(%d): cmd \"%s\", in_fd %d out_fd %d\n",
	// 	getpid(), cmd_str, io->in_fd, io->out_fd);

	// printf("child(%d): dup2 1 %d\n", getpid(), dup2(io->in_fd, STDIN_FILENO));
	// close(io->in_fd);
	// printf("child(%d): dup2 2 %d\n", getpid(), dup2(io->out_fd, STDOUT_FILENO));
	// close(io->out_fd);
	dup2(io->in_fd, STDIN_FILENO);
	dup2(io->out_fd, STDOUT_FILENO);
	// if ((dup2(io->in_fd, STDIN_FILENO) == -1)
	// 	|| (dup2(io->out_fd, STDOUT_FILENO) == -1))
	// 	fatal_error("dup2() failed");

	// printf("child(%d): dup2() done\n", getpid());
	cmd = parse_commnad(cmd_str);
	// if (execve(cmd->argv[0], cmd->argv, info()->envp) == -1)
	if (execve(cmd->exec_path, cmd->argv, info()->envp) == -1)
		fatal_error(cmd->argv[0]);
	exit(0);
}
