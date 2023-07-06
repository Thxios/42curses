/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:48:12 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/06 23:11:22 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

/*
typedef enum e_keycode
{
	KEY_Q = 12,
	KEY_W = 13,
	KEY_E = 14,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_SPACE = 49,
	KEY_LSHIFT = 257,
	KEY_TAB = 48,
	KEY_ESCAPE = 53,
}	t_keycode;
*/

typedef enum e_keycode
{
	KEY_Q = 113,
	KEY_W = 119,
	KEY_E = 101,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_SPACE = 32,
	KEY_LSHIFT = 65505,
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
	char	k_space;
	char	k_lshift;
}			t_keys;

#endif
