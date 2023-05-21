/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:36:31 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/15 13:19:35 by jimlee           ###   ########.fr       */
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

t_color	rgba2color(int r, int g, int b, int a)
{
	r = clip(r, 0, 255);
	g = clip(g, 0, 255);
	b = clip(b, 0, 255);
	a = clip(a, 0, 255);

	return ((a << 24) | (r << 16) | (g << 8) | b);
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

void	reverse_grad(t_color_grad *color)
{
	t_rgb	tmp;

	tmp = color->st;
	color->st = color->ed;
	color->ed = tmp;
}

t_color	blend(t_color_grad *color, double alpha)
{
	int	r;
	int	g;
	int	b;

	r = color->st.r + alpha * (color->ed.r - color->st.r);
	g = color->st.g + alpha * (color->ed.g - color->st.g);
	b = color->st.b + alpha * (color->ed.b - color->st.b);
	// printf("blend %.3f - rgb(%d, %d, %d)\n", alpha, r, g, b);
	return (rgb2color(r, g, b));
}
