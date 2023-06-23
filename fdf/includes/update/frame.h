/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:33:16 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/24 12:04:38 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_H
# define FRAME_H

// # include "render/render.h"
# include "render/buffer.h"
# include "events/events.h"
# include "object/object.h"

// typedef struct s_render
// {
// 	t_image	*img;
// }			t_render;

typedef struct s_upd
{
	// t_render	render;

	t_image		*img;
	t_keys		key;
	t_obj3d		*obj;
	int			cnt;
}				t_upd;

int	frame(t_upd *var);

#endif
