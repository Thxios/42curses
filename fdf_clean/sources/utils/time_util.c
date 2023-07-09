/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:33:32 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 19:38:58 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

long long	get_timestamp(void)
{
	struct timeval	current;

	gettimeofday(&current, 0);
	return ((long long)1e+6 * current.tv_sec + current.tv_usec);
}

long long	elapsed_usec(long long start_time)
{
	long long	current;

	current = get_timestamp();
	return (current - start_time);
}
