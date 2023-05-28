/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:55:52 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/24 11:50:10 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/events.h"
#include <stdio.h>
#include <stdlib.h>

int	quit_event(void)
{
	printf("quit button\n");
	// mlx_destroy_window(mlx(), window());
	exit(0);
	return (0);
}
