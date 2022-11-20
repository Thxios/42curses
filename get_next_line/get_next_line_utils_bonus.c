/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:04:30 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/20 15:48:42 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

t_buffer	*make_new_buffer(t_map *map, int fd, size_t init_capa)
{
	t_buffer	*node;

	node = (t_buffer *)malloc(sizeof(t_buffer));
	if (!node)
		return (NULL);
	node->buffer = (char *)malloc(sizeof(char) * init_capa);
	if (!node->buffer)
		return (NULL);
	node->fd = fd;
	node->len = 0;
	node->capacity = init_capa;
	node->n_lines = 0;
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
