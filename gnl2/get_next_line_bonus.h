/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:03:56 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/20 15:58:48 by jimlee           ###   ########.fr       */
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
	int				fd;
	size_t			len;
	size_t			capacity;
	int				n_lines;
	char			*buffer;
	struct s_buffer	*next;
	struct s_buffer	*prev;
}					t_buffer;

typedef struct s_map
{
	t_buffer	*begin;
	t_buffer	*end;
}				t_map;

char		*get_next_line(int fd);
void		*ft_memmove(void *dest, const void *src, size_t n);
t_buffer	*map_find_buffer(t_map *map, int fd);
t_buffer	*make_new_buffer(t_map *map, int fd, size_t init_capa);
void		delete_buffer(t_map *map, t_buffer *node);
int			push_buffer(t_buffer *buffer, char *s, size_t len);

#endif
