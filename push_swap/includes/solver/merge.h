/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:37:48 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/01 19:00:20 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGE_H
# define MERGE_H

# include "constants.h"

typedef enum e_prior
{
	L1 = 0,
	R1,
	L2
}	t_prior;

void	merge_to_a(int bl, int br, int ar, t_direction dir);
void	merge_to_b(int al, int ar, int br, t_direction dir);

#endif
