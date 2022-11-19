/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:03:56 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/19 19:20:00 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_buffer
{
	char	*buffer;
	size_t	offset;
	size_t	len;
	size_t	capacity;
	int		n_lines;
}			t_buffer;

typedef struct s_manager
{
	t_buffer	*buffers;
	size_t		len;
	size_t		capacity;
}				t_manager;

char	*get_next_line(int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		init_string(t_buffer *str, size_t init_capa);
void	del_string(t_buffer *str);
int		push_string(t_buffer *str, char *c, size_t len);

#endif
