/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:53:45 by jimlee            #+#    #+#             */
/*   Updated: 2023/06/26 01:00:22 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

void	fatal_error(const char *message);
void	command_find_error(const char *message);
void	command_permission_error(const char *message);
void	command_not_found_error(const char *command);
void	parse_eof_error(void);

#endif
