/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:47:17 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/29 00:53:24 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "pipe/io.h"

void	execute_single_pipe(char *cmd_str, t_io *io);
int		execute_pipe(int n_cmds, int is_heredoc, int argc, char *argv[]);

#endif
