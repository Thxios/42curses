/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:03:56 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/17 17:58:45 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_string
{
	char	*buffer;
	size_t	len;
	size_t	capacity;
}			t_string;

char	*get_next_line(int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		init_string(t_string *str, size_t init_capa);
void	del_string(t_string *str);
int		push_string(t_string *str, char c);

#endif
