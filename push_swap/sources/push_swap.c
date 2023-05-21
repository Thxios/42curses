/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:57:46 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/03 11:40:20 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_all(t_array *array)
{
	init_context(array);
	init_config();
}

void	delete_all(t_array *array)
{
	delete_context();
	delete_array(array);
}

t_array	*parse_from_args(int argc, char *argv[])
{
	t_array	*arr;

	arr = new_array();
	if (argc > 1)
	{
		if (parse_args(arr, argc - 1, argv + 1) == -1)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(0);
		}
	}
	return (arr);
}

void	print_instuctions(void)
{
	int	idx;

	idx = 0;
	while (idx < logs()->size)
	{
		ft_printf("%s\n", get_instruction_name(logs()->arr[idx]));
		idx++;
	}
}

int	main(int argc, char *argv[])
{
	t_array	*arr;

	arr = parse_from_args(argc, argv);
	init_all(arr);
	if (arr->size > 0)
	{
		sort_to_a(a()->size, DESC, BACK);
		print_instuctions();
	}
	delete_all(arr);
}
