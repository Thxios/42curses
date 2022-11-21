/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:14:16 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/21 15:44:36 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_H
# define FLAG_H

# include "libft/libft.h"

typedef struct s_flag
{
	int		left_align;
	int		show_positive_sign;
	int		show_positive_blank;
	int		pad_zero;
}			t_flag;

#endif
