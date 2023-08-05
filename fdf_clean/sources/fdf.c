/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:04:53 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/10 10:24:05 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"
#include "initialize.h"
#include "utils/error.h"
#include "object/read_file.h"

int	main(int argc, char *argv[])
{
	t_obj3d	*map_obj;
	t_upd	upd;

	if (argc < 2)
		custom_error("no input file");
	if (argc != 2)
		custom_error("too many input file");
	map_obj = open_map_file(argv[1]);
	initialize(&upd, map_obj);
	start_loop();
	return (0);
}
