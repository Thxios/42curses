/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:33:16 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 19:13:26 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_H
# define UPDATE_H

# include "events/keys.h"
# include "render/buffer.h"
# include "object/object.h"

typedef struct s_upd
{
	t_image	*img;
	t_keys	key;
	t_obj3d	*obj;
	int		cnt;
}			t_upd;

int	frame(t_upd *var);

#endif
