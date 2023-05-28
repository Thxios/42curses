/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:44:47 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/29 01:11:14 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "utils/utils.h"
#include "pipe/pipe.h"

t_io	*alloc_io_arr(int size)
{
	int		idx;
	t_io	*arr;

	arr = safe_calloc(size, sizeof(t_io));
	idx = 0;
	while (idx < size)
	{
		arr[idx].in_fd = -1;
		arr[idx].out_fd = -1;
		idx++;
	}
	return (arr);
}

int	wait_pipe(int n_cmds, int *pid_arr)
{
	int	idx;
	int	exit_code;

	idx = 0;
	while (idx < n_cmds)
	{
		if (pid_arr[idx] > 0)
			waitpid(pid_arr[idx], &exit_code, 0);
		idx++;
	}
	return ((exit_code & 0xff00) >> 8);
}

int	*execute_commands(int n_cmds, char **cmds, t_io *io_arr)
{
	int		*pid_arr;
	int		pipe_fd[2];
	int		idx;

	pid_arr = safe_calloc(n_cmds, sizeof(int));
	idx = 0;
	while (idx < n_cmds)
	{
		if (idx < n_cmds - 1)
		{
			if (pipe(pipe_fd) == -1)
			{
				pipe_fd[0] = -1;
				pipe_fd[1] = -1;
			}
			io_arr[idx].out_fd = pipe_fd[1];
			io_arr[idx + 1].in_fd = pipe_fd[0];
		}
		pid_arr[idx] = fork();
		if (pid_arr[idx] == 0)
			execute_single_pipe(cmds[idx], &io_arr[idx]);
		close(io_arr[idx].out_fd);
		idx++;
	}
	return (pid_arr);
}

t_io	*prepare_pipe_io(int n_cmds, int is_heredoc, int argc, char *argv[])
{
	t_io	*io_arr;

	io_arr = alloc_io_arr(n_cmds);
	io_arr[n_cmds - 1].out_file = argv[argc - 1];
	if (is_heredoc)
	{
		io_arr[0].in_file = argv[2];
		io_arr[0].in_flag |= IN_HERE_DOC;
		io_arr[n_cmds - 1].out_flag |= OUT_APPEND;
	}
	else
		io_arr[0].in_file = argv[1];
	return (io_arr);
}

int	execute_pipe(int n_cmds, int is_heredoc, int argc, char *argv[])
{
	t_io	*io_arr;
	int		*pid_arr;
	int		exit_code;

	io_arr = prepare_pipe_io(n_cmds, is_heredoc, argc, argv);
	if (is_heredoc)
		pid_arr = execute_commands(n_cmds, argv + 3, io_arr);
	else
		pid_arr = execute_commands(n_cmds, argv + 2, io_arr);
	free(io_arr);
	exit_code = wait_pipe(n_cmds, pid_arr);
	free(pid_arr);
	return (exit_code);
}
