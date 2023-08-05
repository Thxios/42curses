/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_util.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:21:51 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/12 02:01:49 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_UTIL_H
# define TIME_UTIL_H

typedef long long t_us;

t_us	get_timestamp(void);
t_us	get_elapsed_time(t_us start);
void	wait_from_until(t_us start, t_us duration);

#endif
