/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:43:48 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 18:51:05 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INFO_H
# define MAP_INFO_H

# include "object/object.h"

typedef struct s_map_info
{
	int	n_row;
	int	n_col;
	int	**height;
}		t_map_info;

int			validate_map_file_extension(char *path);
t_map_info	*parse_file_to_map_info(int fd);
void		delete_map_info(t_map_info *map);
t_obj3d		*read_object_from_file(int fd);

#endif
