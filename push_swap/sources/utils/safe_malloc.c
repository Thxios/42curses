/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:46:37 by jimlee            #+#    #+#             */
/*   Updated: 2023/04/30 04:41:57 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

void	*safe_malloc(size_t size)
{
	void	*allocated;

	allocated = malloc(size);
	if (!allocated)
		exit(-1);
	return (allocated);
}

void	*safe_calloc(size_t n_elem, size_t elem_size)
{
	void	*allocated;

	allocated = malloc(n_elem * elem_size);
	if (!allocated)
		exit(-1);
	ft_memset(allocated, 0, n_elem * elem_size);
	return (allocated);
}
