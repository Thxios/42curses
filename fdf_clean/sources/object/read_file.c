/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:48:58 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 18:49:50 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "utils/error.h"
#include "object/object.h"

t_obj3d	*open_map_file(char *filename)
{
	int		fd;
	t_obj3d	*obj;

	if (!validate_map_file_extension(filename))
		custom_error("invalid file format");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		fatal_error("cannot open map file");
	obj = read_object_from_file(fd);
	if (!obj)
		custom_error("invalid map format");
	return (obj);
}
