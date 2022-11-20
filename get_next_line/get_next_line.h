/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:03:56 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/20 15:53:58 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_buffer
{
	size_t	len;
	size_t	capacity;
	int		n_lines;
	char	*buffer;
}			t_buffer;

char		*get_next_line(int fd);
void		*ft_memmove(void *dest, const void *src, size_t n);
int			init_buffer(t_buffer *buffer, size_t init_capa);
void		delete_buffer(t_buffer *buffer);
int			push_buffer(t_buffer *buffer, char *s, size_t len);

#endif
