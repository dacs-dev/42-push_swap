/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_indexed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 16:04:19 by dcid-san          #+#    #+#             */
/*   Updated: 2025-03-27 16:04:19 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lsti_find(t_lst_indexed_node *node, int num)
{
	while (node)
	{
		if (node->value == num)
			return (1);
		node = node->next;
	}
	return (0);
}

int	ft_lsti_find_smallest(t_lst_indexed_node *node)
{
	int num;

	num = node->value;
	while (node)
	{
		if (node->value <= num)
			num = node->value;
		node = node->next;
	}
	return (num);
}

t_lst_indexed_node	*ft_lsti_addback(t_lst_indexed_node **lst,
					t_lst_indexed_node *new_node)
{
	t_lst_indexed_node	*last;

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

void	free_stack(t_lst_indexed_node *stack)
{
	t_lst_indexed_node	*current;
	t_lst_indexed_node	*next;

	current = stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
