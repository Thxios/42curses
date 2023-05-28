/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:55:20 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/29 01:18:35 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/error.h"
#include "libft/libft.h"
#include "utils/info.h"

void	fatal_error(const char *message)
{
	ft_putstr_fd(info()->exe, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	perror(message);
	exit(1);
}

void	parse_eof_error(void)
{
	ft_putstr_fd("syntax error: unexpected end of file\n", STDERR_FILENO);
	exit(1);
}
