/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:36:09 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/08 19:45:13 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	idx;

	idx = 0;
	while ((src[idx] != '\0') && (idx + 1 < size))
	{
		dest[idx] = src[idx];
		idx++;
	}
	if (size > 0)
		dest[idx] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	idx;
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (len_dest > size)
		return (size + len_src);
	idx = 0;
	while ((idx + len_dest + 1 < size) && (src[idx] != '\0'))
	{
		dest[idx + len_dest] = src[idx];
		idx++;
	}
	dest[idx + len_dest] = '\0';
	return (len_dest + len_src);
}
