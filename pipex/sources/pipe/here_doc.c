/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:06:20 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/29 00:31:27 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "utils/error.h"
#include "libft/libft.h"

int	open_here_doc(char *eof)
{
	char	*line;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		fatal_error("pipe() failed");
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = ft_readline(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strcmp(line, eof) == 0)
		{
			free(line);
			break ;
		}
		write(pipe_fd[1], line, ft_strlen(line));
		write(pipe_fd[1], "\n", 1);
		free(line);
	}
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}
