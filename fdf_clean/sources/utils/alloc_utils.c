/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:20:08 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 20:14:51 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "utils/error.h"

void	*safe_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		fatal_error("malloc fail");
	return (ret);
}

void	*safe_calloc(size_t n_elem, size_t elem_size)
{
	void	*ret;

	ret = malloc(n_elem * elem_size);
	if (!ret)
		fatal_error("malloc fail");
	ft_memset(ret, 0, n_elem * elem_size);
	return (ret);
}
