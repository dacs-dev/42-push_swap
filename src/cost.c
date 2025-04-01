/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-01 03:58:48 by dcid-san          #+#    #+#             */
/*   Updated: 2025-04-01 03:58:48 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost_pa(t_lsti_node *node_a, t_lsti_node *node_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lsti_len(node_a);
	len_b = ft_lsti_len(node_b);
	while (node_a)
	{
		node_a->push_cost = node_a->index;
		if (!(node_a->above_median))
			node_a->push_cost = len_a - (node_a->index);
		if (node_a->target->above_median)
			node_a->push_cost += node_a->target->index;
		else
			node_a->push_cost += len_b - (node_a->target->index);
		node_a = node_a->next;
	}
}

void	ft_lsti_mark_cheap(t_lsti_node *stack)
{
	long		cheapest_value;
	t_lsti_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	set_target_a(t_lsti_node *stack_a, t_lsti_node *stack_b)
{
	t_lsti_node	*current_b;
	t_lsti_node	*target_node;
	long		best_match_index;

	while (stack_a)
	{
		best_match_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->value < stack_a->value
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			stack_a->target = ft_lsti_find_max(stack_b);
		else
			stack_a->target = target_node;
		stack_a = stack_a->next;
	}
}

void	set_target_b(t_lsti_node *stack_a, t_lsti_node *stack_b)
{
	t_lsti_node	*current_a;
	t_lsti_node	*target_node;
	long		best_match_index;

	while (stack_b)
	{
		best_match_index = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			stack_b->target = ft_lsti_find_smallest(stack_a);
		else
			stack_b->target = target_node;
		stack_b = stack_b->next;
	}
}
