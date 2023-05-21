/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:03:37 by jimlee            #+#    #+#             */
/*   Updated: 2023/04/30 04:35:08 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/quick_sort.h"

static int	*mid_elem(int *ia, int *ib, int *ic)
{
	if ((*ia < *ib) != (*ia < *ic))
		return (ia);
	else if ((*ib < *ia) != (*ib < *ic))
		return (ib);
	else
		return (ic);
}

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	quick_sort_internal(int *s, int *e)
{
	int	pivot;
	int	*lo;
	int	*hi;

	swap(e - 1, mid_elem(s, s + ((e - s) / 2), e - 1));
	pivot = *(e - 1);
	lo = s;
	hi = e - 2;
	while (lo < hi)
	{
		while (lo < e && *lo < pivot)
			lo++;
		while (hi > lo && *hi >= pivot)
			hi--;
		if (lo < hi)
			swap(lo, hi);
	}
	swap(lo, e - 1);
	quick_sort(s, lo);
	quick_sort(lo + 1, e);
}

void	quick_sort(int *start, int *end)
{
	if (end - start < 2)
		return ;
	else if (end - start == 2)
	{
		if (*start > *(start + 1))
			swap(start, start + 1);
	}
	else
		quick_sort_internal(start, end);
}

void	sort_array(t_array *arr)
{
	quick_sort(arr->arr, arr->arr + arr->size);
}
