/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:55:19 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/29 01:09:37 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	**parse_env_path(char **envp)
{
	char	*path;
	int		path_idx;

	path_idx = 0;
	while (envp[path_idx] && (ft_strncmp(envp[path_idx], "PATH=", 5) != 0))
		path_idx++;
	if (envp[path_idx])
		path = envp[path_idx] + 5;
	else
		path = "";
	return (ft_split(path, ':'));
}
