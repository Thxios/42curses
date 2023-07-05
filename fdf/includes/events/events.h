/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:03:28 by jimlee            #+#    #+#             */
/*   Updated: 2023/06/23 14:38:29 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "events/keys.h"
# include "events/button.h"

int	quit_event(void);
int	keydown_event(int keycode, t_keys *key);
int	keyup_event(int keycode, t_keys *key);
int	mousedown_event(int button, int x, int y, void *arg);

#endif
