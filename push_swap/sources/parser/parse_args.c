/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:59:24 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/01 19:39:17 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "parser/parser.h"
#include "libft/libft.h"
#include "utils/array.h"

static int	read_integer(char *s, int *out)
{
	int			idx;
	int			sign;
	long long	ret;

	ret = 0;
	sign = 1;
	idx = 0;
	if ((s[idx] == '+') || (s[idx] == '-'))
	{
		if (s[idx] == '-')
			sign = -1;
		idx++;
	}
	if (!ft_isdigit(s[idx]))
		return (-1);
	while (ft_isdigit(s[idx]))
	{
		ret *= 10;
		ret += sign * (s[idx] - '0');
		if ((ret < INT_MIN) || (ret > INT_MAX))
			return (-1);
		idx++;
	}
	*out = ret;
	return (idx);
}

static int	trim_whitespace(char *s)
{
	int	idx;

	idx = 0;
	while (ft_isspace(s[idx]))
		idx++;
	return (idx);
}

static int	parse_single_arg(t_array *arr, char *arg)
{
	int	idx;
	int	num;
	int	read_size;
	int	pushed;

	pushed = 0;
	idx = trim_whitespace(arg);
	while (arg[idx] != '\0')
	{
		read_size = read_integer(&arg[idx], &num);
		if (read_size == -1)
			return (-1);
		push_array(arr, num);
		pushed = 1;
		idx += read_size;
		idx += trim_whitespace(&arg[idx]);
	}
	if (pushed)
		return (0);
	else
		return (-1);
}

int	parse_args(t_array *arr, int argc, char *argv[])
{
	int	idx;

	idx = 0;
	while (idx < argc)
	{
		if (parse_single_arg(arr, argv[idx]) == -1)
			return (-1);
		idx++;
	}
	if (has_duplicated(arr))
		return (-1);
	else
		return (0);
}
