/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_indexed_ext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:04:19 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/31 03:46:41 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lsti_find(t_lsti_node *node, int num)
{
	while (node)
	{
		if (node->value == num)
			return (1);
		node = node->next;
	}
	return (0);
}

t_lsti_node	*ft_lsti_find_max(t_lsti_node *stack)
{
	t_lsti_node	*biggest;

	biggest = stack;
	while (stack)
	{
		if (stack->value > biggest->value)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

t_lsti_node	*ft_lsti_find_smallest(t_lsti_node *node)
{
	t_lsti_node	*curr_min;

	curr_min = node;
	while (node)
	{
		if (node->value < curr_min->value)
			curr_min = node;
		node = node->next;
	}
	return (curr_min);
}

t_lsti_node	*ft_lsti_addback(t_lsti_node **lst,
					t_lsti_node *new_node)
{
	t_lsti_node	*last;

	if (!*lst)
	{
		*lst = new_node;
		(*lst)->prev = NULL;
		(*lst)->next = NULL;
	}
	else
	{
		last = ft_lsti_last(*lst);
		last->next = new_node;
		new_node->prev = last;
		new_node->next = NULL;
	}
	return (*lst);
}

void	free_stack(t_lsti_node *stack)
{
	t_lsti_node	*current;
	t_lsti_node	*next;

	current = stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
