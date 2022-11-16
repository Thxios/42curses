/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:04:22 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/16 17:38:48 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_as_cstring(t_string *str)
{
	char	*cstring;

	if (!str->capacity)
		return (NULL);
	cstring = (char *)malloc(sizeof(char) * (str->len + 1));
	if (!cstring)
		return (NULL);
	ft_memcpy(cstring, str->buffer, str->len);
	cstring[str->len] = '\0';
	return (cstring);
}

char	get_next_line(int fd)
{
	int			ret_null;
	int			read_code;
	t_string	str;
	char		*ret_cstring;

	ret_null = 1;
	init_string(&str, 16);
	while (1)
	{
		read_code = read(file, &c, 1);
		if (read_code == -1)
		{
			ret_null = 1;
			break ;
		}
		else if (read_code == 0)
			break ;
		ret_null = 0;
		if (c == '\n')
			break ;
		if (push_string(&str, c) == -1)
		{
			ret_null = 1;
			break ;
		}
	}
	
}
