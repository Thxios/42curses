/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:04:22 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/18 03:00:36 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*str_as_cstring(t_string *str)
{
	char	*cstring;

	if (str->len == 0)
		return (NULL);
	cstring = (char *)malloc(sizeof(char) * (str->len + 1));
	if (!cstring)
		return (NULL);
	ft_memcpy(cstring, str->buffer, str->len);
	cstring[str->len] = '\0';
	return (cstring);
}

int	get_line_to_tsring(int fd, t_string *str)
{
	int		read_result;
	int		n_bytes;
	char	c;

	while (1)
	{
		n_bytes = read(fd, &c, 1);
		if (n_bytes == -1)
			return (-1);
		else if (n_bytes == 0)
			return (0);
		if (push_string(str, c) == -1)
			return (-1);
		if (c == '\n')
			return (0);
	}
}

char	*get_next_line(int fd)
{
	t_string	str;
	char		*ret_cstring;

	if (init_string(&str, 16) == -1)
		return (NULL);
	if (get_line_to_tsring(fd, &str) == -1)
		ret_cstring = NULL;
	else
		ret_cstring = str_as_cstring(&str);
	del_string(&str);
	return (ret_cstring);
}
