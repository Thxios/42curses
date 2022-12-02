/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:04:15 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/02 16:25:19 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include "libft/libft.h"

int	get_len_num(long long n, int n_base);
int	ft_putnbr_base(long long num, char *base);
int	ft_putnbr(long long n);
int	get_len_num_u(unsigned long long n, int n_base);
int	ft_putnbr_base_u(unsigned long long num, char *base);

int	ft_max(int a, int b);
int	put_n_times(char c, int n);

int	ft_putchar(char c);
int	ft_putstr(const char *s);

#endif
