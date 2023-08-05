/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:59:02 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/10 10:15:57 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/draw.h"
#include "render/color.h"
#include "utils/utils.h"
#include "utils/point.h"

void	draw_line_low(t_image *img, t_pos p1, t_pos p2, t_color c)
{
	int	dx;
	int	dy;
	int	yi;
	int	disc;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	disc = 2 * dy - dx;
	while (p1.x <= p2.x)
	{
		set_pixel_image(img, p1.x, p1.y, c);
		if (disc > 0)
		{
			p1.y += yi;
			disc -= 2 * dx;
		}
		disc += 2 * dy;
		p1.x++;
	}
}

void	draw_line_high(t_image *img, t_pos p1, t_pos p2, t_color c)
{
	int	dx;
	int	dy;
	int	xi;
	int	disc;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	disc = 2 * dx - dy;
	while (p1.y <= p2.y)
	{
		set_pixel_image(img, p1.x, p1.y, c);
		if (disc > 0)
		{
			p1.x += xi;
			disc -= 2 * dy;
		}
		disc += 2 * dx;
		p1.y++;
	}
}

void	draw_line(t_image *img, t_pos p1, t_pos p2, t_color c)
{
	if (ft_abs(p1.x - p2.x) >= ft_abs(p1.y - p2.y))
	{
		if (p1.x < p2.x)
			draw_line_low(img, p1, p2, c);
		else
			draw_line_low(img, p2, p1, c);
	}
	else
	{
		if (p1.y < p2.y)
			draw_line_high(img, p1, p2, c);
		else
			draw_line_high(img, p2, p1, c);
	}
}
