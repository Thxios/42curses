/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:33:58 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/10 18:58:33 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

typedef struct s_process_info
{
	char	*exe;
	char	**envp;
	char	**env_path;
}			t_process_info;

t_process_info	*info(void);

#endif
