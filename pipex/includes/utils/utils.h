/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:58:40 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/08 14:55:11 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

void	*safe_malloc(size_t n_bytes);
void	*safe_calloc(size_t n_elem, size_t elem_size);

void	free_2d_str_arr(char **arr);

#endif
