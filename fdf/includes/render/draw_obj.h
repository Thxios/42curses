/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obj.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:32:57 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/24 11:45:41 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_OBJ_H
# define DRAW_OBJ_H

# include "object/object.h"
# include "render/buffer.h"

void	draw_object(t_image *img, t_obj3d *obj);

#endif
