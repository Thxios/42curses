/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:03:28 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 19:17:50 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "update.h"

int	quit_event(t_upd *upd);
int	keydown_event(int keycode, t_upd *upd);
int	keyup_event(int keycode, t_upd *upd);
int	mousedown_event(int button, int x, int y, t_upd *upd);

#endif
