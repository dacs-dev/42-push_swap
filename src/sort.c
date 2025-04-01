/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-01 03:43:34 by dcid-san          #+#    #+#             */
/*   Updated: 2025-04-01 03:43:34 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_b(t_data *data)
{
	t_lsti_node	*best;

	best = ft_lsti_find_cheap(data->stack_a);
	if (best->above_median
		&& best->target->above_median)
		op_both_stacks(data, best, rr);
	else if (!(best->above_median)
		&& !(best->target->above_median))
		op_both_stacks(data, best, rrr);
	move_top(data, best, 'a');
	move_top(data, best->target, 'b');
	pb(data);
}

void	push_to_sack_a(t_data *data)
{
	move_top(data, data->stack_b->target, 'a');
	pa(data);
}

void	last_sort(t_data *data)
{
	while ((data->stack_a)->value
		!= ft_lsti_find_smallest(data->stack_a)->value)
	{
		if (ft_lsti_find_smallest(data->stack_a)->above_median)
			ra(data, 1);
		else
			rra(data, 1);
	}
}

void	sort(t_data *data)
{
	int	len_a;

	len_a = ft_lsti_len(data->stack_a);
	if (len_a-- > 3 && !ft_lsti_is_sorted(data->stack_a))
		pb(data);
	if (len_a-- > 3 && !ft_lsti_is_sorted(data->stack_a))
		pb(data);
	while (len_a-- > 3 && !ft_lsti_is_sorted(data->stack_a))
	{
		refresh_stack_a(data->stack_a, data->stack_b);
		push_to_stack_b(data);
	}
	sort_three(data);
	while (data->stack_b)
	{
		refresh_stack_b(data->stack_a, data->stack_b);
		push_to_sack_a(data);
	}
	ft_lsti_refresh_index(data->stack_a);
	last_sort(data);
}
