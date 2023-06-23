/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:24:32 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/11 13:39:23 by jimlee           ###   ########.fr       */
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
	int		in_flag;
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
