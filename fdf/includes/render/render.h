/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:37:10 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/21 16:22:06 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "render/buffer.h"

typedef struct s_render
{
	t_image	*img;
}			t_render;

int	render_frame(t_render *var);

#endif
