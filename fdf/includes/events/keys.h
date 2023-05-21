/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:48:12 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/17 15:58:09 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

typedef enum e_keycode
{
	KEY_Q = 113,
	KEY_W = 119,
	KEY_E = 101,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_UP = 65362,
	KEY_DOWN = 65361,
	KEY_LEFT = 65364,
	KEY_RIGHT = 65363,
	KEY_TAB = 65289,
	KEY_ESCAPE = 65307,
}	t_keycode;

typedef struct s_keys
{
	char	k_q;
	char	k_w;
	char	k_e;
	char	k_a;
	char	k_s;
	char	k_d;
	char	k_up;
	char	k_down;
	char	k_left;
	char	k_right;
}			t_keys;

#endif
