/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unique.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 04:15:29 by jimlee            #+#    #+#             */
/*   Updated: 2023/04/30 04:39:28 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/array.h"
#include "utils/quick_sort.h"

int	has_duplicated(t_array *arr)
{
	t_array	*arr_copy;
	int		idx;
	int		is_duplicated;

	arr_copy = copy_array(arr);
	sort_array(arr_copy);
	idx = 0;
	is_duplicated = 0;
	while (idx < arr->size - 1)
	{
		if (arr_copy->arr[idx] == arr_copy->arr[idx + 1])
		{
			is_duplicated = 1;
			break ;
		}
		idx++;
	}
	delete_array(arr_copy);
	return (is_duplicated);
}
