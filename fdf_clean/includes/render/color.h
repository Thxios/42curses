/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:34:56 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 16:22:03 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef unsigned int	t_color;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}		t_rgb;

typedef struct s_color_grad
{
	t_rgb	st;
	t_rgb	ed;
}			t_color_grad;

t_color			rgb2color(int r, int g, int b);
t_rgb			color2rgb(t_color c);
t_color_grad	make_grad(t_color st, t_color ed);
t_color			blend(t_color_grad *color, double alpha);
t_color			get_color_heatmap(double alpha);

#endif
