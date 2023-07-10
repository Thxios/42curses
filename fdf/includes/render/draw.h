/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:14:33 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/10 10:14:25 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "render/buffer.h"
# include "utils/point.h"
# include "render/color.h"

void	fill_image(t_image *img, t_color c);
void	set_pixel_image(t_image *img, int x, int y, t_color c);
void	draw_line(t_image *img, t_pos p1, t_pos p2, t_color c);
void	draw_line_grad(t_image *img, t_pos p1, t_pos p2, t_color_grad c_grad);

#endif
