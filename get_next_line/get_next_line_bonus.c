/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:04:22 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/21 17:00:41 by jimlee           ###   ########.fr       */
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

t_buffer	*map_find_buffer(t_map *map, int fd)
{
	t_buffer	*node;

	if (fd < 0)
		return (NULL);
	node = map->begin;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	return (make_new_buffer(map, fd, 16));
}

char	*buffer_as_string(t_buffer *buffer)
{
	size_t	len;
	char	*cstring;

	len = 0;
	while ((len < buffer->len) && (buffer->buffer[len] != '\n'))
		len++;
	if ((len < buffer->len) && (buffer->buffer[len] == '\n'))
		len++;
	if (len == 0)
		return (NULL);
	cstring = (char *)malloc(sizeof(char) * (len + 1));
	if (!cstring)
		return (NULL);
	if (buffer->buffer[len - 1] == '\n')
		buffer->n_lines--;
	ft_memmove(cstring, buffer->buffer, len);
	cstring[len] = '\0';
	ft_memmove(buffer->buffer, buffer->buffer + len, buffer->len - len);
	buffer->len -= len;
	return (cstring);
}

int	get_line_buffer(int fd, t_buffer *buffer)
{
	int		n_bytes;
	int		get_line_result;
	char	*c;

	c = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!c)
		return (-1);
	get_line_result = 0;
	while (get_line_result == 0)
	{
		n_bytes = read(fd, c, BUFFER_SIZE);
		if (n_bytes == -1)
			get_line_result = -1;
		else if (n_bytes == 0)
			get_line_result = 2;
		else if (push_buffer(buffer, c, n_bytes) == -1)
			get_line_result = -1;
		else if (buffer->n_lines > 0)
			get_line_result = 1;
	}
	free(c);
	return (get_line_result);
}

char	*get_next_line(int fd)
{
	static t_map	buffer_map;
	t_buffer		*buffer;
	int				get_line_res;
	char			*ret_cstring;

	buffer = map_find_buffer(&buffer_map, fd);
	if (!buffer)
		return (NULL);
	if (buffer->n_lines > 0)
		ret_cstring = buffer_as_string(buffer);
	else
	{
		get_line_res = get_line_buffer(fd, buffer);
		if ((get_line_res == 1) || (get_line_res == 2))
			ret_cstring = buffer_as_string(buffer);
		else
			ret_cstring = NULL;
	}
	if (!ret_cstring)
		delete_buffer(&buffer_map, buffer);
	return (ret_cstring);
}
