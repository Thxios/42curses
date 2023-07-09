/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:36:31 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 16:21:44 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/color.h"
#include "utils/utils.h"

#include <stdio.h>

t_color	rgb2color(int r, int g, int b)
{
	r = clip(r, 0, 255);
	g = clip(g, 0, 255);
	b = clip(b, 0, 255);

	return ((r << 16) | (g << 8) | b);
}

t_rgb	color2rgb(t_color c)
{
	return ((t_rgb){(c & 0xff0000) >> 16, (c & 0xff00) >> 8, c & 0xff});
}

t_color_grad	make_grad(t_color st, t_color ed)
{
	// t_rgb s = color2rgb(st), e = color2rgb(ed);
	// printf("grad(rgb(%d, %d, %d)~rgb(%d, %d, %d))\n",
	// 	s.r, s.g, s.b, e.r, e.g, e.b);
	return ((t_color_grad){color2rgb(st), color2rgb(ed)});
}

t_color	blend(t_color_grad *color, double alpha)
{
	int	r;
	int	g;
	int	b;

	alpha = clipf(alpha, 0, 1);
	r = color->st.r + alpha * (color->ed.r - color->st.r);
	g = color->st.g + alpha * (color->ed.g - color->st.g);
	b = color->st.b + alpha * (color->ed.b - color->st.b);
	// printf("blend %.3f - rgb(%d, %d, %d)\n", alpha, r, g, b);
	return (rgb2color(r, g, b));
}

t_color	get_color_heatmap(double alpha)
{
	int	r;
	int	g;
	int	b;

	alpha = clipf(alpha, 0, 1);
	if (alpha < 0.5)
	{
		alpha *= 2;
		r = 255 * alpha;
		g = 255 * alpha;
		b = 255;
	}
	else
	{
		alpha = 1 - ((alpha - 0.5) * 2);
		r = 255;
		g = 255 * alpha;
		b = 255 * alpha;
	}
	return (rgb2color(r, g, b));
}
