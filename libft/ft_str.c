/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:54:48 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/08 20:43:15 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_strdup(const char *src)
{
	int		idx;
	size_t	src_len;
	char	*duplicated;

	src_len = ft_strlen(src);
	duplicated = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!duplicated)
		return (NULL);
	idx = 0;
	while (src[idx] != '\0')
	{
		duplicated[idx] = src[idx];
		idx++;
	}
	duplicated[idx] = '\0';
	return (duplicated);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	len_s2;
	size_t	idx;

	len_s2 = ft_strlen(s2);
	if (len_s2 == 0)
		return ((char *)s1);
	idx = 0;
	while ((idx + len_s2 <= len) && (s1[idx] != '\0'))
	{
		if (ft_strncmp(s1 + idx, s2, len_s2) == 0)
			return ((char *)(s1 + idx));
		idx++;
	}
	return (NULL);
}
