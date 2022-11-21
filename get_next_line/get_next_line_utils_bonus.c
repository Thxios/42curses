/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:04:30 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/21 17:00:36 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_buffer	*init_buffer(int fd, size_t init_capa)
{
	t_buffer	*buffer;

	buffer = (t_buffer *)malloc(sizeof(t_buffer));
	if (!buffer)
		return (NULL);
	buffer->buffer = (char *)malloc(sizeof(char) * init_capa);
	if (!buffer->buffer)
	{
		free(buffer);
		return (NULL);
	}
	buffer->fd = fd;
	buffer->len = 0;
	buffer->capacity = init_capa;
	buffer->n_lines = 0;
	return (buffer);
}

t_buffer	*make_new_buffer(t_map *map, int fd, size_t init_capa)
{
	t_buffer	*node;

	node = init_buffer(fd, init_capa);
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = map->end;
	if (map->end)
	{
		map->end->next = node;
		map->end = node;
	}
	else
	{
		map->begin = node;
		map->end = node;
	}
	return (node);
}

void	delete_buffer(t_map *map, t_buffer *node)
{
	if (map->begin == node)
		map->begin = node->next;
	if (map->end == node)
		map->end = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free(node->buffer);
	free(node);
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
