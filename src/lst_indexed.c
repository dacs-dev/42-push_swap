/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_indexed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:04:19 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/31 07:17:59 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lsti_node	*ft_lsti_newnode(int value)
{
	t_lsti_node	*node;

	node = malloc(sizeof(t_lsti_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->target = NULL;
	node->cheapest = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_lsti_deletenode(t_lsti_node **head, t_lsti_node *node)
{
	if (!head || !*head || !node)
		return ;
	if (*head == node && node->next == NULL)
	{
		free(node);
		*head = NULL;
		return ;
	}
	if (node->prev)
		node->prev->next = node->next;
	else
		*head = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free(node);
}

t_lsti_node	*ft_lsti_last(t_lsti_node *node)
{
	t_lsti_node	*current;

	if (!node)
		return (NULL);
	current = node;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}

t_lsti_node	*ft_lsti_addfront(t_lsti_node **lst,
					t_lsti_node *node)
{
	if (!lst || !node)
		return (NULL);
	node->next = *lst;
	node->prev = NULL;
	if (*lst)
		(*lst)->prev = node;
	*lst = node;
	return (*lst);
}

int	ft_lsti_len(t_lsti_node *node)
{
	int	count;

	if (!node)
		return (0);
	count = 0;
	while (node)
	{
		node = node->next;
		count++;
	}
	return (count);
}
