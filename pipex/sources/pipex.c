/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:44:47 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/29 01:16:58 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_info(char *exe, char **envp)
{
	info()->exe = exe;
	info()->envp = envp;
	info()->env_path = parse_env_path(envp);
}

void	delete_info(void)
{
	free_2d_str_arr(info()->env_path);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	n_cmds;
	int	is_heredoc;
	int	exit_code;

	if (argc < 2)
		return (0);
	is_heredoc = (ft_strcmp(argv[1], "here_doc") == 0);
	if (is_heredoc)
		n_cmds = argc - 4;
	else
		n_cmds = argc - 3;
	if (n_cmds < 1)
		return (0);
	set_info(argv[0], envp);
	exit_code = execute_pipe(n_cmds, is_heredoc, argc, argv);
	delete_info();
	return (exit_code);
}
