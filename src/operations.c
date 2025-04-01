/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:32:56 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/31 03:47:59 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_both_stacks(t_data *data,
	t_lsti_node *cheapest_node, void (*op)(t_data *))
{
	while (data->stack_b != cheapest_node->target
		&& data->stack_a != cheapest_node)
		op(data);
	ft_lsti_refresh_index(data->stack_a);
	ft_lsti_refresh_index(data->stack_b);
}

void	pa(t_data *data)
{
	t_lsti_node	*to_move;

	if (data->stack_b)
	{
		to_move = data->stack_b;
		data->stack_b = data->stack_b->next;
		if (data->stack_b)
			data->stack_b->prev = NULL;
		ft_lsti_addfront(&(data->stack_a), to_move);
		data->size_b--;
		data->size_a++;
		data->operations++;
		write(1, "pa\n", 3);
	}
}

void	pb(t_data *data)
{
	t_lsti_node	*to_move;

	if (data->stack_a)
	{
		to_move = data->stack_a;
		data->stack_a = data->stack_a->next;
		if (data->stack_a)
			data->stack_a->prev = NULL;
		to_move->next = NULL;
		ft_lsti_addfront(&(data->stack_b), to_move);
		data->size_a--;
		data->size_b++;
		data->operations++;
		write(1, "pb\n", 3);
	}
}
