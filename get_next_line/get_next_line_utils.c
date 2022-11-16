/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:04:30 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/16 17:22:55 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_cptr;
	char	*src_cptr;
	size_t	idx;

	src_cptr = (char *)src;
	dest_cptr = (char *)dest;
	idx = 0;
	while (idx < n)
	{
		dest_cptr[idx] = src_cptr[idx];
		idx++;
	}
	return (dest);
}

void	init_string(t_string *str, size_t init_capa)
{
	str->capacity = init_capa;
	str->buffer = (char *)malloc(sizeof(char) * init_capa);
	if (str->buffer)
		del_string(str);
	str->len = 0;
}

void	del_string(t_string *str)
{
	free(str->buffer);
	str->buffer = NULL;
	str->capacity = 0;
}

void	expand_buffer(t_string *str)
{
	char	*expanded;
	size_t	new_capa;

	new_capa = str->capacity * 2;
	expanded = (char *)malloc(sizeof(char) * new_capa);
	if (!expanded)
	{
		del_string(str);
		return ;
	}
	ft_memcpy(expanded, str->buffer, str->capacity);
	free(str->buffer);
	str->buffer = expanded;
	str->capacity = new_capa;
}

int	push_string(t_string *str, char c)
{
	if (str->len == str->capacity)
		expand_buffer(str);
	if (!str->capacity)
		return (-1);
	str->buffer[str->len] = c;
	str->len++;
	return (0);
}
