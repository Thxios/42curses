/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:04:30 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/20 16:39:05 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_cptr;
	char	*src_cptr;
	int		idx;
	int		direction;

	if (src < dest)
	{
		idx = n - 1;
		direction = -1;
	}
	else
	{
		idx = 0;
		direction = 1;
	}
	src_cptr = (char *)src;
	dest_cptr = (char *)dest;
	while (0 <= idx && idx < (int)n)
	{
		dest_cptr[idx] = src_cptr[idx];
		idx += direction;
	}
	return (dest);
}

int	init_buffer(t_buffer *buffer, size_t init_capa)
{
	if (buffer->capacity > 0)
		return (0);
	buffer->buffer = (char *)malloc(sizeof(char) * init_capa);
	if (!buffer->buffer)
		return (-1);
	buffer->len = 0;
	buffer->capacity = init_capa;
	buffer->n_lines = 0;
	return (0);
}

void	delete_buffer(t_buffer *buffer)
{
	free(buffer->buffer);
	buffer->buffer = NULL;
	buffer->len = 0;
	buffer->capacity = 0;
	buffer->n_lines = 0;
}

int	expand_buffer(t_buffer *buffer)
{
	char	*expanded;
	size_t	new_capa;

	new_capa = 2 * buffer->capacity;
	expanded = (char *)malloc(sizeof(char) * new_capa);
	if (!expanded)
		return (-1);
	ft_memmove(expanded, buffer->buffer, buffer->len);
	free(buffer->buffer);
	buffer->capacity = new_capa;
	buffer->buffer = expanded;
	return (0);
}

int	push_buffer(t_buffer *buffer, char *s, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx < len)
	{
		if (buffer->len == buffer->capacity)
		{
			if (expand_buffer(buffer) == -1)
				return (-1);
		}
		buffer->buffer[buffer->len] = s[idx];
		if (s[idx] == '\n')
			buffer->n_lines++;
		idx++;
		buffer->len++;
	}
	return (0);
}
