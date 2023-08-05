/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:43:56 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 19:44:29 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "update.h"
#include "context/context.h"
#include "events/events.h"

void	initialize_mlx_hook(t_upd *upd)
{
	mlx_hook(window(), 17, 0, quit_event, upd);
}
