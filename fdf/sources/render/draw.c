/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:09:09 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/05 18:36:12 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/draw.h"

void	fill(t_image *img, t_color c)
{
	int	idx;

	idx = 0;
	while (idx < img->w * img->h)
	{
		img->data[idx] = c;
		idx++;
	}
}

void	set_pixel(t_image *img, int x, int y, t_color c)
{
	if ((x < 0) || (x >= img->w))
		return ;
	if ((y < 0) || (y >= img->h))
		return ;
	img->data[y * img->w + x] = c;
}
