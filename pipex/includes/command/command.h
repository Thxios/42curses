/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:45:01 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/29 00:57:26 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include <unistd.h>

typedef struct s_cmd
{
	char	*exec_path;
	char	**argv;
}			t_cmd;

void	delete_command(t_cmd *cmd);
t_cmd	*parse_commnad(char *s);
char	*find_executable(char *exe);

#endif
