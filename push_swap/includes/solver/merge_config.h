/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_config.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:47:31 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/01 19:15:05 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGE_CONFIG_H
# define MERGE_CONFIG_H

# include <limits.h>
# include "utils/deque.h"

# define MAX LLONG_MAX
# define MIN LLONG_MIN

typedef struct s_config
{
	t_deque		*q1;
	t_deque		*q2;
	void		(*push_fn)();
	void		(*rot1_fn)();
	void		(*rot2_fn)();
	int			(*comp)(long long, long long);
	long long	identity;
}				t_config;

typedef enum e_merge_type
{
	A_ASC = 0,
	A_DESC,
	B_ASC,
	B_DESC
}	t_merge_type;

t_config	*get_config(t_merge_type merge_type);
void		init_config(void);

#endif
