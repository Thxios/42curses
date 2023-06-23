/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:22:42 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/25 00:05:05 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "utils/utils.h"
#include "render/buffer.h"
#include "context/context.h"
#include "libft.h"

#include <stdio.h>

t_image	*new_image(int width, int height)
{
	t_image	*img;

	img = safe_malloc(sizeof(t_image));
	img->w = width;
	img->h = height;
	img->image = mlx_new_image(mlx(), width, height);
	img->data = (t_color *)mlx_get_data_addr(
		img->image, &img->depth, &img->len_line, &img->endian);

	printf("Image(%dx%d, depth=%d, len=%d)\n", img->w, img->h, img->depth, img->len_line);
	return (img);
}

void	delete_image(t_image *img)
{
	mlx_destroy_image(mlx(), img->image);
	free(img);
}
