/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:43:56 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 20:24:55 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "update.h"
#include "context/context.h"
#include "events/keys.h"
#include "events/events.h"

int	keydown_event2(int keycode, t_upd *upd)
{
	if (keycode == KEY_ESCAPE)
		quit_event(upd);
	return (0);
}

void	initialize_mlx_hook(t_upd *upd)
{
	mlx_hook(window(), 17, 0, quit_event, upd);
	mlx_hook(window(), 2, 1 << 0, keydown_event2, upd);
}
