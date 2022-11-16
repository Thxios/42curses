/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:03:56 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/16 17:28:58 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_string
{
	char	*buffer;
	size_t	len;
	size_t	capacity;
}			t_string;

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	init_string(t_string *str, size_t init_capa);
void	del_string(t_string *str);
int		push_string(t_string *str, char c);

#endif
