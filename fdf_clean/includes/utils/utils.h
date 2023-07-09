/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:39:13 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 19:39:18 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

void	*safe_malloc(size_t size);
void	*safe_calloc(size_t n_elem, size_t elem_size);

int		clip(int val, int min, int max);
double	clipf(double val, double min, double max);
double	maxf(double a, double b);
int		ft_abs(int num);

int		*map_atoi_to_splited(char *s, int *size);

#endif
