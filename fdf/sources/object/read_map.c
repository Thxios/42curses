/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:14:37 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/28 13:20:34 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "object/object.h"
#include "libft.h"

t_obj3d	*read_map_object(int fd)
{
	char	*line;

	while (1)
	{
		line = ft_readline(fd);
		if (!line)
			break;

		free(line);
	}
}


