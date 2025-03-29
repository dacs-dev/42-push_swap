/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_indexed_ext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:04:19 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/28 17:24:24 by krusty           ###   ########.fr       */
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

unsigned int	ft_lsti_find_index(t_lst_indexed_node *node, unsigned int num)
{
	unsigned int	count;

	count = 0;
	while (node)
	{
		if (node->index == num)
			break ;
		node = node->next;
		count ++;
	}
	return (count);
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
