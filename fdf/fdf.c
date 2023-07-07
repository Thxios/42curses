/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:04:53 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/07 16:47:23 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char *argv[])
{
	t_upd	upd_var;

	init_context();
	launch_window(WIDTH, HEIGHT, "test");
	// mlx_key_hook(window(), keydown_event, &keys);
	mlx_hook(window(), 17, 0, quit_event, NULL);
	mlx_hook(window(), 2, 1 << 0, keydown_event, &upd_var.key);
	mlx_hook(window(), 3, 1 << 1, keyup_event, &upd_var.key);
	mlx_hook(window(), 4, 1 << 2, mousedown_event, NULL);

	printf("camera proj mat:\n");
	print_matrix(camera()->proj_mat);

	// img = new_image(1280, 960);
	upd_var.img = new_image(WIDTH, HEIGHT);
	if (argc == 2)
	{
		printf("read from %s\n", argv[1]);
		int fd = open(argv[1], O_RDONLY);
		upd_var.obj = new_from_file(fd);
		close(fd);
		translate_object(upd_var.obj, (t_vec){0, 0, 26});
	}
	else
	{

		upd_var.obj = new_obj_test();
	}


	mlx_loop_hook(mlx(), frame, &upd_var);
	mlx_loop(mlx());
	printf("here\n");


	return (0);
}
