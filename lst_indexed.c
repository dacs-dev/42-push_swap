#include "push_swap.h"

t_lst_indexed_node *ft_lsti_newnode(int value)
{
	t_lst_indexed_node *node = malloc(sizeof(t_lst_indexed_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1; // Se actualizará después
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void ft_lsti_deletenode(t_lst_indexed_node **head, t_lst_indexed_node *node)
{
	if (!head || !*head || !node)
		return;
	if (*head == node && node->next == NULL)
	{
		free(node);
		*head = NULL;
		return;
	}
	if (node->prev)
		node->prev->next = node->next;
	else
		*head = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free(node);
}

t_lst_indexed_node *ft_lsti_last(t_lst_indexed_node *node)
{
	if (!node)
		return NULL;

	t_lst_indexed_node *current = node;
	while (current->next != NULL)
	{ // Avanza hasta que next sea NULL
		current = current->next;
	}
	return current;
}

t_lst_indexed_node *ft_lsti_addfront(t_lst_indexed_node **lst, t_lst_indexed_node *node)
{
	if (!lst || !node)
		return NULL;

	node->next = *lst;
	node->prev = NULL;

	if (*lst)
		(*lst)->prev = node;

	*lst = node;
	return *lst;
}

int ft_lsti_find(t_lst_indexed_node *node, int num)
{
	while (node)
	{
		if (node->value == num)
			return (1);
		node = node->next;
	}
	return (0);
}

int ft_lsti_find_smallest(t_lst_indexed_node *node)
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

t_lst_indexed_node *ft_lsti_addback(t_lst_indexed_node **lst, t_lst_indexed_node *new_node)
{
	t_lst_indexed_node *last;
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
	return *lst;
}

void free_stack(t_lst_indexed_node *stack)
{
	t_lst_indexed_node *current = stack;
	t_lst_indexed_node *next;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
