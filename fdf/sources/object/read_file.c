/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:55:29 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/05 17:50:50 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object/read_file.h"
#include "utils/ptr_array.h"
#include "utils/utils.h"
#include "libft.h"

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

t_map_info	*parse_file(int fd)
{
	char		*line;
	char		**splited;
	t_ptr_arr	*arr;
	t_map_info	*map;
	int			idx;
	int			n_col;

	arr = new_ptr_array();
	while (1)
	{
		line = ft_readline(fd);
		if (!line)
			break;
		push_ptr_array(arr, line);
	}
	if (arr->size == 0)
	{
		delete_ptr_array(arr);
		return (NULL);
	}
	map = safe_calloc(1, sizeof(t_map_info));
	map->n_row = arr->size;
	map->height = safe_calloc(map->n_row, sizeof(int *));
	map->height[0] = map_atoi_to_splited(arr->arr[0], &map->n_col);
	if (map->n_col == 0)
	{
		delete_ptr_array(arr);
		delete_map_info(map);
		return (NULL);
	}
	idx = 1;
	while (idx < arr->size) {
		map->height[idx] = map_atoi_to_splited(arr->arr[1], &n_col);
		if (n_col != map->n_col)
		{
			delete_ptr_array(arr);
			delete_map_info(map);
			return (NULL);
		}
	}
	delete_ptr_array(arr);
	return (map);
}

t_obj3d	*new_from_file(int fd)
{

}
