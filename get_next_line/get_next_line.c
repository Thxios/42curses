/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:04:22 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/20 15:58:27 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (buffer->buffer[len - 1] == '\n')
		buffer->n_lines--;
	cstring = (char *)malloc(sizeof(char) * (len + 1));
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
	static t_buffer	buffer;
	int				get_line_res;
	char			*ret_cstring;

	if (init_buffer(&buffer, 16) == -1)
		return (NULL);
	if (buffer.n_lines > 0)
		ret_cstring = buffer_as_string(&buffer);
	else
	{
		get_line_res = get_line_buffer(fd, &buffer);
		if ((get_line_res == 1) || (get_line_res == 2))
			ret_cstring = buffer_as_string(&buffer);
		else
			ret_cstring = NULL;
		if ((get_line_res == -1) || (get_line_res == 2))
			delete_buffer(&buffer);
	}
	return (ret_cstring);
}
