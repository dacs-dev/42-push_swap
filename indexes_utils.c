/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 16:04:03 by dcid-san          #+#    #+#             */
/*   Updated: 2025-03-27 16:04:03 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*create_int_lst(t_data *data)
{
	int					*values;
	t_lst_indexed_node	*current;
	int					i;

	values = malloc(data->size_a * sizeof(int));
	if (values == NULL)
		error_exit(data, "Error en maloc de create_int_lst\n", 34);
	i = 0;
	current = data->stack_a;
	while (i < data-> size_a)
	{
		values[i++] = current->value;
		current = current->next;
	}
	return (values);
}

void	assign_indices(t_data *data)
{
	int					*values;
	int					i;
	t_lst_indexed_node	*current;

	values = create_int_lst(data);
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