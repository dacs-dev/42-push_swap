/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:04:03 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/29 00:41:45 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*create_int_lst(t_data *data)
{
	int					*values;
	t_lst_indexed_node	*current;
	unsigned int			i;

	values = malloc(data->size_a * sizeof(int));
	if (values == NULL)
		error_exit(data, MALLOC_ERR, 24, NULL);
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
	unsigned int					i;
	t_lst_indexed_node	*current;

	values = create_int_lst(data);
	ft_lstsort_int(values, data->size_a);
	current = data->stack_a;
	while (current != NULL)
	{
		i = 0;
		while (i < data-> size_a)
		{
			if (current->value == *(values + i))
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free(values);
}
