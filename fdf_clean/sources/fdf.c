/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:04:53 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 18:47:02 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char *argv[])
{
	t_obj3d	*map_obj;
	t_upd	upd;

	if (argc != 2)
		custom_error("no input file");
	map_obj = open_map_file(argv[1]);
	initialize(&upd);
	upd.obj = map_obj;
	start_loop();
	return (0);
}
