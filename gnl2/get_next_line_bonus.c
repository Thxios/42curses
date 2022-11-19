/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:04:22 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/19 19:21:27 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_buffer	*find_fd_buffer(int fd, t_manager *manager)
{
	int	idx = 0;

	while (idx < manager->len)
	{
		if
	}
}

char	*str_as_cstring(t_buffer *str)
{
	size_t	len;
	char	*cstring;

	len = 0;
	while ((str->offset + len < str->len)
		&& (str->buffer[str->offset + len] != '\n'))
		len++;
	if ((str->offset + len < str->len)
		&& (str->buffer[str->offset + len] == '\n'))
		len++;
	if (len == 0)
		return (NULL);
	cstring = (char *)malloc(sizeof(char) * (len + 1));
	cstring[len] = '\0';
	ft_memcpy(cstring, &str->buffer[str->offset], len);
	str->offset += len;
	if (cstring[len - 1] == '\n')
		str->n_lines--;
	return (cstring);
}

int	get_line_to_tsring(int fd, t_buffer *str)
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
		else if (push_string(str, c, n_bytes) == -1)
			get_line_result = -1;
		else if (str->n_lines > 0)
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

	if (init_string(&buffer, 10) == -1)
		return (NULL);
	if (buffer.n_lines > 0)
		ret_cstring = str_as_cstring(&buffer);
	else
	{
		get_line_res = get_line_to_tsring(fd, &buffer);
		if ((get_line_res == 1) || (get_line_res == 2))
			ret_cstring = str_as_cstring(&buffer);
		else
			ret_cstring = NULL;
		if ((get_line_res == -1) || (get_line_res == 2))
			del_string(&buffer);
	}
	return (ret_cstring);
}
