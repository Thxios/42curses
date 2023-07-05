/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:34:56 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/05 18:30:23 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef unsigned int	t_color;

t_color	rgb2color(int r, int g, int b);
t_color	rgba2color(int r, int g, int b, int a);

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

t_rgb			color2rgb(t_color c);
t_color_grad	make_grad(t_color st, t_color ed);
void			reverse_grad(t_color_grad *color);
t_color			blend(t_color_grad *color, double alpha);

#endif
