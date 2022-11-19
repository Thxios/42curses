/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:04:30 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/19 19:02:34 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_cptr;
	char	*src_cptr;
	size_t	idx;

	dest_cptr = (char *)dest;
	src_cptr = (char *)src;
	idx = 0;
	while (idx < n)
	{
		dest_cptr[idx] = src_cptr[idx];
		idx++;
	}
	return (dest);
}

int	init_string(t_buffer *str, size_t init_capa)
{
	if (str->capacity > 0)
		return (0);
	str->capacity = init_capa;
	str->buffer = (char *)malloc(sizeof(char) * init_capa);
	if (!str->buffer)
	{
		del_string(str);
		return (-1);
	}
	str->offset = 0;
	str->len = 0;
	return (0);
}

void	del_string(t_buffer *str)
{
	free(str->buffer);
	str->buffer = NULL;
	str->capacity = 0;
	str->offset = 0;
	str->len = 0;
}

int	expand_buffer(t_buffer *str)
{
	char	*expanded;
	size_t	new_len;
	size_t	new_capa;

	new_len = str->len - str->offset;
	if (new_len < str->capacity)
		new_capa = str->capacity;
	else
		new_capa = 2 * str->capacity;
	expanded = (char *)malloc(sizeof(char) * new_capa);
	if (!expanded)
	{
		del_string(str);
		return (-1);
	}
	ft_memcpy(expanded, &str->buffer[str->offset], new_len);
	free(str->buffer);
	str->offset = 0;
	str->len = new_len;
	str->capacity = new_capa;
	str->buffer = expanded;
	return (0);
}

int	push_string(t_buffer *str, char *c, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx < len)
	{
		if (str->len == str->capacity)
		{
			if (expand_buffer(str) == -1)
				return (-1);
		}
		str->buffer[str->len] = c[idx];
		if (c[idx] == '\n')
			str->n_lines++;
		idx++;
		str->len++;
	}
	return (0);
}
