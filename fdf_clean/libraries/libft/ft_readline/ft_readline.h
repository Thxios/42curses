/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:03:56 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/06 23:03:47 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

# define INIT_BUFFER_SIZE 16

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

char	*ft_readline(int fd);

#endif
