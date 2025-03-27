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

t_lst_indexed_node	*ft_lsti_newnode(int value)
{
	t_lst_indexed_node	*node;

	node = malloc(sizeof(t_lst_indexed_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_lsti_deletenode(t_lst_indexed_node **head, t_lst_indexed_node *node)
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

t_lst_indexed_node	*ft_lsti_last(t_lst_indexed_node *node)
{
	t_lst_indexed_node	*current;

	if (!node)
		return (NULL);
	current = node;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}

t_lst_indexed_node	*ft_lsti_addfront(t_lst_indexed_node **lst,
					t_lst_indexed_node *node)
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
