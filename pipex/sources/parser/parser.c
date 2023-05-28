/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:46:25 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/29 01:09:21 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser/parser.h"
#include "utils/utils.h"
#include "libft/libft.h"
#include "utils/char_array.h"
#include "utils/str_array.h"
#include "utils/error.h"

char	*parse_single_char(char *s, t_chr_arr *arr)
{
	if (*s == '\\')
	{
		s++;
		if (*s == '\0')
			push_chr_array(arr, '\\');
	}
	if (*s != '\0')
	{
		push_chr_array(arr, *s);
		s++;
	}
	return (s);
}

char	*parse_single_quote(char *s, t_chr_arr *arr)
{
	s++;
	while ((*s != '\0') && (*s != '\''))
	{
		push_chr_array(arr, *s);
		s++;
	}
	if (*s == '\'')
		s++;
	else
		parse_eof_error();
	return (s);
}

char	*parse_double_quote(char *s, t_chr_arr *arr)
{
	s++;
	while ((*s != '\0') && (*s != '\"'))
	{
		s = parse_single_char(s, arr);
	}
	if (*s == '\"')
		s++;
	else
		parse_eof_error();
	return (s);
}

char	*parse_single_token(char **s)
{
	t_chr_arr	*arr;
	char		*token;

	arr = new_chr_array();
	while (**s != '\0' && !ft_isspace(**s))
	{
		if (**s == '\"')
			*s = parse_double_quote(*s, arr);
		else if (**s == '\'')
			*s = parse_single_quote(*s, arr);
		else
			*s = parse_single_char(*s, arr);
	}
	if (arr->size)
		token = to_string(arr);
	else
		token = NULL;
	delete_chr_array(arr);
	return (token);
}

t_str_arr	*parse_tokens(char *s)
{
	t_str_arr	*tokens;
	char		*token;

	tokens = new_str_array();
	while (*s != '\0')
	{
		while (ft_isspace(*s))
			s++;
		token = parse_single_token(&s);
		if (token)
			push_str_array(tokens, token);
	}
	if (tokens->size == 0)
		push_str_array(tokens, ft_strdup(""));
	return (tokens);
}
