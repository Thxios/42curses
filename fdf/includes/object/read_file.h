/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:53:37 by jimlee            #+#    #+#             */
/*   Updated: 2023/06/27 20:04:01 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_FILE_H
# define READ_FILE_H

# include "object/object.h"

typedef struct s_map_info
{
	int	n_row;
	int	n_col;
	int	**height;
}		t_map_info;

t_obj3d	*new_from_file(int fd);

#endif
