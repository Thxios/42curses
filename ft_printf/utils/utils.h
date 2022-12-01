/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:04:15 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/01 12:46:31 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include "libft/libft.h"

int		get_len_num(long long n, int n_base);
void	ft_putnbr_base(long long num, char *base);
void	ft_putnbr(long long n);
int		get_len_num_u(unsigned long long n, int n_base);
void	ft_putnbr_base_u(unsigned long long num, char *base);

int		ft_max(int a, int b);
int		put_n_times(char c, int n);

#endif
