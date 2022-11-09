/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:37:09 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/09 17:51:29 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len_src;
	size_t	idx;
	char	*mapped;

	len_src = ft_strlen(s);
	mapped = (char *)malloc(sizeof(char) * (len_src + 1));
	if (!mapped)
		return (NULL);
	idx = 0;
	while (idx < len_src)
	{
		mapped[idx] = (*f)(idx, s[idx]);
		idx++;
	}
	return (mapped);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		(*f)(idx, &s[idx]);
		idx++;
	}
}
