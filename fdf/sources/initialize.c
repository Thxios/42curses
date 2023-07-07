/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:03:22 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/07 16:14:23 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_hook(t_upd *upd_var)
{
	mlx_hook(window(), 17, 0, quit_event, 0);
	mlx_hook(window(), 2, 1 << 0, keydown_event, &upd_var->key);
	mlx_hook(window(), 3, 1 << 1, keyup_event, &upd_var->key);
	mlx_hook(window(), 4, 1 << 2, mousedown_event, 0);
}
