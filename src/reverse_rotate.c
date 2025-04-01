/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-01 04:28:18 by dcid-san          #+#    #+#             */
/*   Updated: 2025-04-01 04:28:18 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data, int show_msg)
{
	t_lsti_node	*last;
	t_lsti_node	*second_last;

	if (!data->stack_a || data->size_a < 2)
		return ;
	last = ft_lsti_last(data->stack_a);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = data->stack_a;
	data->stack_a->prev = last;
	data->stack_a = last;
	data->operations++;
	if (show_msg)
		write(1, "rra\n", 4);
}

void	rrb(t_data *data, int show_msg)
{
	t_lsti_node	*last;
	t_lsti_node	*second_last;

	if (!data->stack_b || data->size_b < 2)
		return ;
	last = ft_lsti_last(data->stack_b);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = data->stack_b;
	data->stack_b->prev = last;
	data->stack_b = last;
	data->operations++;
	if (show_msg)
		write(1, "rrb\n", 4);
}

void	rrr(t_data *data)
{
	rra(data, 0);
	rrb(data, 0);
	data->operations--;
	write(1, "rrr\n", 4);
}
