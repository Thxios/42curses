/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:54:28 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/12 18:00:45 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	size_t	alloc_size;
	void	*allocated;

	alloc_size = nelem * elsize;
	if (alloc_size == 0)
		alloc_size = 1;
	allocated = malloc(alloc_size);
	if (!allocated)
		return (NULL);
	ft_memset(allocated, 0, alloc_size);
	return (allocated);
}
