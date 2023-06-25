/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_prefix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:50:18 by jimlee            #+#    #+#             */
/*   Updated: 2023/06/26 01:01:00 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command/command.h"
#include "utils/utils.h"
#include "utils/info.h"
#include "utils/error.h"
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
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
		idx++;
	}
	return (NULL);
}

char	*find_executable(char *exe)
{
	char	*exe_path;

	if ((ft_strlen(exe) == 0) || ft_strchr(exe, '/'))
	{
		if (access(exe, F_OK) == -1)
			command_find_error(exe);
		if (access(exe, X_OK) == -1)
			command_permission_error(exe);
		return (ft_strdup(exe));
	}
	else
	{
		exe_path = find_path_prefix(exe, info()->env_path);
		if (!exe_path)
			command_not_found_error(exe);
		if (access(exe_path, X_OK) == -1)
			command_permission_error(exe_path);
		return (exe_path);
	}
}
