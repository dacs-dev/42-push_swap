/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 15:01:27 by dcid-san          #+#    #+#             */
/*   Updated: 2025-03-27 15:01:27 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	calc_rotate_direction(t_data *data, unsigned int index)
{
	unsigned int		position;
	t_lst_indexed_node	*current;

	current = data->stack_a;
	position = 0;
	while (current != NULL)
	{
		position++;
		if (current->index == index)
			break ;
		current = current->next;
	}
	if (position <= data->size_a / 2)
		return (RA);
	else
		return (RRA);
}

int	calc_chunkn(unsigned int size)
{
	if (size <= 100)
		return (5);
	else if (size <= 500)
		return (10);
	else
		return (25);
}

void	move_chunk_b(t_data *data, unsigned int min_index,
		unsigned int max_index)
{
	t_lst_indexed_node	*current;
	int					rotate_type;

	while (min_index <= max_index)
	{
		rotate_type = calc_rotate_direction(data, min_index);
		current = data -> stack_a;
		while (current->index != min_index)
		{
			if (rotate_type == RA)
				ra(data);
			else
				rra(data);
			current = current ->next;
		}
		pb(data);

		min_index++;
	}
}

void	move_chunk_a(t_data *data)
{
	while (data -> stack_b != NULL)
		pa(data);
}

void	k_sort(t_data *data, int k)
{
	unsigned int	chunk_size;
	unsigned int	min_index;
	unsigned int	max_index;
	unsigned int	i;

	i = k;
	chunk_size = data -> size_a / k;
	while (i > 0)
	{
		min_index = i * chunk_size;
		max_index = (i +1 * chunk_size) - 1;
		move_chunk_b(data, min_index, max_index);
		move_chunk_a(data);
		i--;
	}
}
