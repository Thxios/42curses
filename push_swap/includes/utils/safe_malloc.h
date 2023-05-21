/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:46:50 by jimlee            #+#    #+#             */
/*   Updated: 2023/04/30 04:42:37 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAFE_MALLOC_H
# define SAFE_MALLOC_H

# include <stdlib.h>

void	*safe_malloc(size_t bytes);
void	*safe_calloc(size_t n_elem, size_t elem_size);

#endif
