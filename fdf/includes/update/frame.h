/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:33:16 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/21 16:21:47 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_H
# define FRAME_H

# include "render/render.h"
# include "events/events.h"

typedef struct s_upd
{
	t_render	render;
	t_keys		key;
	int			cnt;
}				t_upd;

int	frame(t_upd *var);

#endif
