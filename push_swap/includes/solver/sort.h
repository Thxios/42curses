/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:50:27 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/02 12:14:44 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "solver/constants.h"

void	sort_to_a(int n, t_direction d, t_position dest);
void	sort_to_b(int n, t_direction d, t_position dest);
int		check_a_back_sorted(int n, t_direction d);

#endif
