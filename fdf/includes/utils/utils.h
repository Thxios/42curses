/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:39:13 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/15 12:36:52 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

int		clip(int val, int min, int max);
void	swap(int *a, int *b);
int		ft_abs(int num);

void	*safe_malloc(size_t n_bytes);
void	*safe_calloc(size_t n_elem, size_t elem_size);

#endif
