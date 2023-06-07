/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:54:48 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/08 15:13:25 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	idx;
	int		src_is_ended;

	idx = 0;
	src_is_ended = 0;
	while (idx < n)
	{
		src_is_ended = src_is_ended || (src[idx] == '\0');
		if (src_is_ended)
			dest[idx] = '\0';
		else
			dest[idx] = src[idx];
		idx++;
	}
	return (dest);
}

char	*ft_strdup(const char *src)
{
	size_t	src_len;
	char	*duplicated;

	src_len = ft_strlen(src);
	duplicated = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!duplicated)
		return (NULL);
	ft_strlcpy(duplicated, src, src_len + 1);
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
		if (ft_strncmp(&s1[idx], s2, len_s2) == 0)
			return ((char *)&s1[idx]);
		idx++;
	}
	return (NULL);
}
