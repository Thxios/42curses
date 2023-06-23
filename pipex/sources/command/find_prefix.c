/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_prefix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:50:18 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/29 01:06:24 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command/command.h"
#include "utils/utils.h"
#include "utils/info.h"
#include "libft/libft.h"

char	*find_path_prefix(char *exe, char **paths)
{
	int		idx;
	char	*full_path;
	size_t	exec_len;
	size_t	path_len;

	idx = 0;
	exec_len = ft_strlen(exe);
	while (paths[idx])
	{
		path_len = ft_strlen(paths[idx]);
		full_path = ft_calloc(path_len + exec_len + 2, sizeof(char));
		ft_memcpy(full_path, paths[idx], path_len);
		full_path[path_len] = '/';
		ft_memcpy(full_path + path_len + 1, exe, exec_len);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		idx++;
	}
	return (ft_strdup(exe));
}

char	*find_executable(char *exe)
{
	if ((ft_strlen(exe) == 0) || ft_strchr(exe, '/'))
		return (ft_strdup(exe));
	else
		return (find_path_prefix(exe, info()->env_path));
}
