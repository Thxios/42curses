/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:20:03 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/15 01:11:52 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# include "render/color.h"

typedef struct s_image
{
	void	*image;
	t_color	*data;
	int		w;
	int		h;
	int		depth;
	int		len_line;
	int		endian;
}			t_image;

t_image	*new_image(int width, int height);
void	delete_image(t_image *img);

#endif
