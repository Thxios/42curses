/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:39:13 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/05 18:23:29 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

int		clip(int val, int min, int max);
double	clipf(double val, double min, double max);
double	maxf(double a, double b);
void	swap(int *a, int *b);
int		ft_abs(int num);
char	**split_and_size(char *s, int *size);
int		*map_atoi_to_splited(char *s, int *size);

void	*safe_malloc(size_t n_bytes);
void	*safe_calloc(size_t n_elem, size_t elem_size);

#endif
