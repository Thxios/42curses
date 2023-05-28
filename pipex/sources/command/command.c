/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:46:25 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/29 01:06:05 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command/command.h"
#include "parser/parser.h"
#include "utils/utils.h"
#include "utils/info.h"
#include "utils/str_array.h"

t_cmd	*new_command(void)
{
	t_cmd	*ret;

	ret = safe_malloc(sizeof(t_cmd));
	ret->exec_path = NULL;
	ret->argv = NULL;
	return (ret);
}

void	delete_command(t_cmd *cmd)
{
	free(cmd->exec_path);
	free_2d_str_arr(cmd->argv);
	free(cmd);
}

t_cmd	*parse_commnad(char *s)
{
	t_str_arr	*tokens;
	char		*exe;
	t_cmd		*command;

	tokens = parse_tokens(s);
	exe = find_executable(tokens->arr[0]);
	command = new_command();
	command->exec_path = exe;
	command->argv = to_2d_str_arr(tokens);
	delete_str_array(tokens);
	return (command);
}
