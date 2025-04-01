/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:04:03 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/31 02:07:18 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lsti_refresh_index(t_lsti_node *node)
{
	int	i;
	int	median;

	i = 0;
	if (!node)
		return ;
	median = ft_lsti_len(node) / 2;
	while (node)
	{
		node->index = i;
		if (i <= median)
			node->above_median = 1;
		else
			node->above_median = 0;
		node = node->next;
		++i;
	}
}

void	refresh_stack_a(t_lsti_node *stack_a, t_lsti_node *stack_b)
{
	ft_lsti_refresh_index(stack_a);
	ft_lsti_refresh_index(stack_b);
	set_target_a(stack_a, stack_b);
	set_cost_pa(stack_a, stack_b);
	ft_lsti_mark_cheap(stack_a);
}

void	refresh_stack_b(t_lsti_node *stack_a, t_lsti_node *stack_b)
{
	ft_lsti_refresh_index(stack_a);
	ft_lsti_refresh_index(stack_b);
	set_target_b(stack_a, stack_b);
}
