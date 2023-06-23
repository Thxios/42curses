/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:50:43 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/29 01:07:21 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/info.h"

t_process_info	*info(void)
{
	static t_process_info	process_info;

	return (&process_info);
}
