/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:04:22 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/20 15:42:13 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*str_as_cstring(t_string *str)
{
	size_t	len;
	char	*cstring;

	len = 0;
	// printf("make cstring - offset %lu, len %lu, capa %lu, nl %d\n",
		// str->offset, str->len, str->capacity, str->n_lines);
	while ((str->offset + len < str->len)
		&& (str->buffer[str->offset + len] != '\n'))
		len++;
	if ((str->offset + len < str->len)
		&& (str->buffer[str->offset + len] == '\n'))
		len++;
	if (len == 0)
		return (NULL);
	// printf("cstring len %lu\n", len);
	cstring = (char *)malloc(sizeof(char) * (len + 1));
	cstring[len] = '\0';
	ft_memcpy(cstring, &str->buffer[str->offset], len);
	str->offset += len;
	if (cstring[len - 1] == '\n')
		str->n_lines--;
	return (cstring);
}

int	get_line_to_tsring(int fd, t_string *str)
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
	static t_string	buffer;
	int				get_line_res;
	char			*ret_cstring;

	if (init_string(&buffer, 10) == -1)
		return (NULL);
	// printf("get line start - offset %lu, len %lu, capa %lu, nl %d\n",
		// buffer.offset, buffer.len, buffer.capacity, buffer.n_lines);
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
	// printf("get line done\n");
	return (ret_cstring);
}
