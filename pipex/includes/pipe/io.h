/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:24:32 by jimlee            #+#    #+#             */
/*   Updated: 2023/06/26 01:13:41 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

typedef struct s_io
{
	int		in_fd;
	int		out_fd;
	char	*in_file;
	char	*out_file;
	int		out_flag;
}	t_io;

typedef enum e_in_flg
{
	IN_HERE_DOC = 1
}	t_in_flg;

typedef enum e_out_flg
{
	OUT_APPEND = 1
}	t_out_flg;

int	open_here_doc(char *eof);

#endif
