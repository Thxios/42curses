/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:55:29 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/10 10:34:02 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "object/map_info.h"
#include "utils/utils.h"
#include "utils/ptr_array.h"

void	delete_map_info(t_map_info *map)
{
	int	row;

	row = 0;
	while (row < map->n_row)
	{
		free(map->height[row]);
		row++;
	}
	free(map->height);
	free(map);
}

t_ptr_arr	*read_lines_as_ptr_arr(int fd)
{
	char		*line;
	t_ptr_arr	*lines;

	lines = new_ptr_array();
	while (1)
	{
		line = ft_readline(fd);
		if (!line)
			break ;
		push_ptr_array(lines, line);
	}
	return (lines);
}

int	lines_to_map_info(t_ptr_arr *lines, t_map_info *map)
{
	int	idx;
	int	tmp_n_col;

	if (lines->size == 0)
		return (-1);
	map->n_row = lines->size;
	map->height = safe_calloc(map->n_row, sizeof(int *));
	map->height[0] = map_atoi_to_splited(lines->arr[0], &map->n_col);
	if (map->n_col == 0)
		return (-1);
	idx = 1;
	while (idx < lines->size)
	{
		map->height[idx] = map_atoi_to_splited(lines->arr[idx], &tmp_n_col);
		if (tmp_n_col != map->n_col)
			return (-1);
		idx++;
	}
	return (0);
}

t_map_info	*parse_file_to_map_info(int fd)
{
	t_ptr_arr	*lines;
	t_map_info	*map;

	lines = read_lines_as_ptr_arr(fd);
	map = safe_calloc(1, sizeof(t_map_info));
	if (lines_to_map_info(lines, map) == -1)
	{
		delete_map_info(map);
		map = NULL;
	}
	delete_ptr_array(lines, free);
	return (map);
}
