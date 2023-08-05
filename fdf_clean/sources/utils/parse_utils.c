/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:25:37 by jimlee            #+#    #+#             */
/*   Updated: 2023/07/09 19:28:12 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "utils/utils.h"

int	*map_atoi_to_splited(char *s, int *size)
{
	char	**ret;
	int		*arr;
	int		cnt;

	ret = ft_split(s, ' ');
	cnt = 0;
	while (ret[cnt])
		cnt++;
	*size = cnt;
	arr = safe_calloc(cnt, sizeof(int));
	while (cnt--)
	{
		arr[cnt] = ft_atoi(ret[cnt]);
		free(ret[cnt]);
	}
	free(ret);
	return (arr);
}
