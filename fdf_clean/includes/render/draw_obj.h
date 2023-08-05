/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obj.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:32:57 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 20:19:09 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_OBJ_H
# define DRAW_OBJ_H

# include "object/object.h"
# include "render/buffer.h"
# include "utils/point.h"
# include "utils/matrix.h"

t_pos	scr_to_pixel(t_vec4 scr_p);
void	draw_edge_internal(t_image *img, t_vertex *a, t_vertex *b);
void	draw_object_to_img(t_image *img, t_obj3d *obj);

#endif
