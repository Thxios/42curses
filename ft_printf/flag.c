/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:14:03 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/21 15:44:50 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flag.h"

t_flag	*parse_flag(const char *s)
{
	int		idx;
	t_flag	*ret;

	ret = (t_flag *)malloc(sizeof(t_flag));
	if (!ret)
		return (NULL);
	ft_memset(ret, 0, sizeof(t_flag));
	idx = 0;
}
