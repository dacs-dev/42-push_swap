/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:36:53 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/27 14:32:00 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(t_lst_indexed_node *stack, const char *stack_name)
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
		printf("%-3d │ %-6d │ %-6lu\n", position++, current->value, current->index);
		current = current->next;
	}

	printf("═════════════════════\n\n");
}
void ft_free_split(char **arr)
{
	char **tmp = arr;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(arr);
}

int error_exit(t_data *data, char *msg, int msg_size)
{
	free_stack(data->stack_a);
	free_stack(data->stack_b);
	free(data);
	write(2, msg, msg_size);
	return (1);
}

t_lst_indexed_node *parse_args(int argc, char **argv, t_data *data)
{
	int           i;
	long          number;
	unsigned long size;
	char        **arg_lst;
	char        **tmp_arg_lst;

	i = 1;
	size = 0;
	while (i < argc)
	{
		arg_lst = ft_split(argv[i], ' ');
		if (!arg_lst)
			return (error_exit(data, "Error: Fallo al dividir argumentos\n", 35), NULL);
		tmp_arg_lst = arg_lst;
		while (*arg_lst)
		{
			if (!str_isnum(*arg_lst))
				return (ft_free_split(tmp_arg_lst), error_exit(data, "Error: Se ha encontrado un carácter no numérico\n", 50), NULL);

			number = ft_atol(*arg_lst);
			if (number < INT_MIN || number > INT_MAX)
				return (ft_free_split(tmp_arg_lst), error_exit(data, "Error: Uno de los numeros introducidos excede del rango de int\n", 63), NULL);

			if (ft_lsti_find(data->stack_a, number))
			{
				return (ft_free_split(tmp_arg_lst), error_exit(data, "Error: Se ha encontrado un valor duplicado\n", 43), NULL);
			}
			t_lst_indexed_node *new_node = ft_lsti_newnode((int) number);
			if (!new_node)
				return (ft_free_split(tmp_arg_lst), error_exit(data, "Error: Fallo de memoria\n", 24), NULL);
			new_node->index = size;
			ft_lsti_addback(&(data->stack_a), new_node);
			arg_lst++;
			size++;
		}
		ft_free_split(tmp_arg_lst);
		i++;
	}
	data->size_a = size;
	return (data->stack_a);
}

int is_sorted(t_lst_indexed_node *stack)
{
	while (stack->next)
	{
		if (stack->index != stack->next->index - 1)
			return 0;
		stack = stack->next;
	}
	return 1;
}

void	assign_indices(t_data *data)
{
	int					*values;
	int					i;
	t_lst_indexed_node	*current;

	values = malloc(data->size_a * sizeof(int));
	i = 0;
	current = data->stack_a;
	while (i < data-> size_a)
	{
		values[i++] = current->value;
		current = current->next;
	}
	ft_lstsort_int(values, data->size_a);
	current = data->stack_a;
	while (current)
	{
		i = 0;
		while (i < data-> size_a)
		{
			if (current->value == values[i])
			{
				current->index = i++;
				break ;
			}
		}
		current = current->next;
	}
	free(values);
}

int main(int argc, char **argv)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (error_exit(data, "Error: Insuficiencia de memoria para malloc\n", 45));
	data->stack_b = NULL;
	data->stack_a = NULL;
	data->size_a = 0;
	data->size_b = 0;
	data->operations = 0;
	if (argc < 2)
		return (error_exit(data, "Es necesario incluir 1 argumento por lo menos\n", 46));

	if (!parse_args(argc, argv, data))
		return (1);
	if (data->stack_a)
		print_list(data->stack_a, "Stack A");

	assign_indices(data);
	push_swap(data);

	print_list(data->stack_a, "Stack A");
	print_list(data->stack_b, "Stack B");
	printf("Total Operations: %d\n", data->operations);

	free_stack(data->stack_a);
	free_stack(data->stack_b);
	free(data);
	return (0);
}
