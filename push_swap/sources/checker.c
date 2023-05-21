/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:04:46 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/03 11:40:53 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_all(t_array *array)
{
	init_context(array);
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

void	do_operation_from_stdin(void)
{
	char	*line;
	t_inst	inst;

	while (1)
	{
		line = ft_readline(STDIN_FILENO);
		if (!line)
			break ;
		inst = get_instruction_by_name(line);
		free(line);
		if (inst == NONE)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(0);
		}
		get_instruction_function(inst)();
	}
}

int	main(int argc, char *argv[])
{
	t_array	*arr;

	arr = parse_from_args(argc, argv);
	init_all(arr);
	if (arr->size > 0)
	{
		do_operation_from_stdin();
		if (check_a_back_sorted(arr->size, DESC))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	delete_all(arr);
}
