/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:36:53 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/29 01:42:14 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>


//DELETE ME ONLY FOR DEBUGGING
void	print_list(t_lst_indexed_node *stack, const char *stack_name)
{
	t_lst_indexed_node *current;
	int                 position = 0;

	if (!stack)
	{
		printf("%s: (vacío)\n", stack_name);
		return;
	}

	current = stack;
	printf("═════ %s ═════\n", stack_name);
	printf("Pos │ Valor  │ Índice\n");


	while (current != NULL)
	{
		printf("%-3d │ %-6d │ %-6u\n", position++, current->value, current->index);
		current = current->next;
	}

	printf("═════════════════════\n\n");
}



void error_exit(t_data *data, char *msg, int msg_size, char** split)
{
	(void) *msg;
	(void) msg_size;
	ft_free_split(split);
	free_stack(data->stack_a);
	free_stack(data->stack_b);
	free(data);
	if(msg != NULL)
		write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

void	check_arg_lst(t_data *data, char **arg_lst, unsigned int *size)
{
	long				number;
	char				**tmp_arg_lst;
	t_lst_indexed_node	*new_node;

	tmp_arg_lst = arg_lst;
	while (*arg_lst)
	{
		if (!str_isnum(*arg_lst))
			error_exit(data, NAN_ERR, 50, tmp_arg_lst);
		number = ft_atol(*arg_lst);
		if (number < INT_MIN || number > INT_MAX)
			error_exit(data, LIMIT_ERR, 29, tmp_arg_lst);

		if (ft_lsti_find(data->stack_a, (int)number))
			error_exit(data, DUP_ERR, 43, tmp_arg_lst);
		new_node = ft_lsti_newnode((int) number);
		if (!new_node)
			error_exit(data, MALLOC_ERR, 24, tmp_arg_lst);
		new_node->index = *size;
		ft_lsti_addback(&(data->stack_a), new_node);
		arg_lst++;
		*size = *size + 1;
	}
	ft_free_split(tmp_arg_lst);
}

t_lst_indexed_node	*parse_args(int argc, char **argv, t_data *data)
{
	int				i;
	unsigned int	size;
	char			**arg_lst;

	i = 1;
	size = 0;
	while (i < argc)
	{
		if(argv[i][0] != '\0')
		{
			arg_lst = ft_split(argv[i], ' ');
			if (!arg_lst)
				error_exit(data, "Error\n", 6, NULL);
			check_arg_lst(data, arg_lst, &size);
		}
		else
			error_exit(data, "Error\n", 6, NULL);
		i++;
	}
	data->size_a = size;
	return (data->stack_a);
}



int	main(int argc, char **argv)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		error_exit(data, MALLOC_ERR, 24, NULL);
	data->stack_b = NULL;
	data->stack_a = NULL;
	data->size_a = 0;
	data->size_b = 0;
	data->operations = 0;
	if (argc < 2)
		error_exit(data, NULL, 53, NULL);
	
	parse_args(argc, argv, data);
	assign_indices(data);
	if (!ft_lsti_is_sorted(data->stack_a))
	{
		push_swap(data);
	}
	//print_list(data->stack_a, "A");
	free_stack(data->stack_a);
	free_stack(data->stack_b);
	free(data);
	return (0);
}
