/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-01 04:10:15 by dcid-san          #+#    #+#             */
/*   Updated: 2025-04-01 04:10:15 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lsti_node	*ft_lsti_find_cheap(t_lsti_node *node)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	move_top(t_data *data, t_lsti_node *top_node, char stack_name)
{
	if (stack_name == 'a')
	{
		while (data->stack_a != top_node)
		{
			if (top_node->above_median)
				ra(data, 1);
			else
				rra(data, 1);
		}
	}
	else if (stack_name == 'b')
	{
		while (data->stack_b != top_node)
		{
			if (top_node->above_median)
				rb(data, 1);
			else
				rrb(data, 1);
		}
	}
}
