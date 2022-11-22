/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:14:03 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/22 13:20:01 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

int	parse_flag(const char *s, t_format *format)
{
	int	idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		if (ft_strchr("-0# +", s[idx]))
		{
			if (s[idx] == '-')
				format->left_align = 1;
			else if (s[idx] == '0')
				format->pad_zero = 1;
			else if (s[idx] == '#')
				format->sharp = 1;
			else if (s[idx] == ' ')
				format->show_positive_blank = 1;
			else if (s[idx] == '+')
				format->show_positive_sign = 1;
		}
		else
			break ;
		idx++;
	}
	return (idx);
}

int	parse_width(const char *s, t_format *format)
{
	int	idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		if (ft_isdigit(s[idx]))
		{
			format->min_width *= 10;
			format->min_width += s[idx] - '0';
		}
		else
			break ;
		idx++;
	}
	return (idx);
}

int	parse_precision(const char *s, t_format *format)
{
	int	idx;

	idx = 0;
	if (s[idx] == '.')
	{
		while (s[idx] != '\0')
		{
			if (ft_isdigit(s[idx]))
			{
				format->precision *= 10;
				format->precision += s[idx] - '0';
			}
			else
				break ;
			idx++;
		}
	}
	return (idx);
}

int	parse_format(const char *s, t_format *format)
{
	if (s[0] == 'c')
		format->type = c;
	else if (s[0] == 's')
		format->type = s;
	else if (s[0] == 'p')
		format->type = p;
	else if (s[0] == 'd')
		format->type = d;
	else if (s[0] == 'i')
		format->type = i;
	else if (s[0] == 'u')
		format->type = u;
	else if (s[0] == 'x')
		format->type = x;
	else if (s[0] == 'X')
		format->type = X;
	else if (s[0] == '%')
		format->type = percent;
	else
		return (0);
	return (1);
}
