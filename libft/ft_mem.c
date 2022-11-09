/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:40:44 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/08 15:30:14 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*s_cptr;
	size_t	idx;

	s_cptr = (char *)s;
	idx = 0;
	while (idx < n)
	{
		s_cptr[idx] = c;
		idx++;
	}
	return (s);
}

void	*ft_bzero(void *s, size_t n)
{
	return (ft_memset(s, 0, n));
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_cptr;
	const char	*src_cptr = src;
	size_t		idx;

	dest_cptr = (char *)dest;
	idx = 0;
	while (idx < n)
	{
		dest_cptr[idx] = src_cptr[idx];
		idx++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_cptr;
	const char	*src_cptr = src;
	int			idx;
	int			direction;

	dest_cptr = (char *)dest;
	if (src <= dest && dest < src + n)
	{
		idx = n - 1;
		direction = -1;
	}
	else
	{
		idx = 0;
		direction = 1;
	}
	while (0 <= idx && idx < (int)n)
	{
		dest_cptr[idx] = src_cptr[idx];
		idx += direction;
	}
	return (dest);
}
