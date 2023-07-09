/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:42:30 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 20:33:36 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZE_H
# define INITIALIZE_H

# include "update.h"
# include "object/object.h"

void	initialize_mlx_hook(t_upd *upd);
void	initialize(t_upd *upd, t_obj3d *map_obj);
void	start_loop(void);

#endif
