/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:32:56 by dcid-san          #+#    #+#             */
/*   Updated: 2024/11/20 15:33:02 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void sa(t_data *data)
{
	t_lst_indexed_node *first;
	t_lst_indexed_node *second;

	if (!data->stack_a || !data->stack_a->next)
		return;

	first = data->stack_a;
	second = first->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;

	second->prev = NULL;
	second->next = first;
	first->prev = second;

	data->stack_a = second;
	data->operations++;
	print_list(data->stack_a, "Stack A After sa");
	print_list(data->stack_b, "Stack B After sa");
}

void sb(t_data *data)
{
	t_lst_indexed_node *first;
	t_lst_indexed_node *second;

	if (!data->stack_b || !data->stack_b->next)
		return;

	first = data->stack_b;
	second = first->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	data->stack_b = second;
	data->operations++;
	print_list(data->stack_a, "Stack A After sb");
	print_list(data->stack_b, "Stack B After sb");
}

void ss(t_data *data)
{
	sa(data);
	sb(data);
	print_list(data->stack_a, "Stack A After ss");
	print_list(data->stack_b, "Stack B After ss");
}

void pa(t_data *data)
{
	t_lst_indexed_node *to_move;

	if (data->stack_b)
	{
		to_move = data->stack_b;
		data->stack_b = data->stack_b->next;
		if (data->stack_b)
			data->stack_b->prev = NULL;
		ft_lsti_addfront(&(data->stack_a), to_move);
		data->size_b--;
		data->size_a++;
		data->operations++;
		print_list(data->stack_a, "Stack A After pa");
		print_list(data->stack_b, "Stack B After pa");
	}
}

void pb(t_data *data)
{
	t_lst_indexed_node *to_move;

	if (data->stack_a)
	{
		to_move = data->stack_a;
		data->stack_a = data->stack_a->next;
		if (data->stack_a)
			data->stack_a->prev = NULL;
		ft_lsti_addfront(&(data->stack_b), to_move);
		data->size_a--;
		data->size_b++;
		data->operations++;
		print_list(data->stack_a, "Stack A After pb");
		print_list(data->stack_b, "Stack B After pb");
	}
}

void ra(t_data *data)
{
	t_lst_indexed_node *last;
	t_lst_indexed_node *second;
	if (!data->stack_a || data->size_a < 2)
		return;
	last = ft_lsti_last(data->stack_a);
	second = data->stack_a->next;
	last->next = data->stack_a;
	data->stack_a->prev = last;
	data->stack_a->next = NULL;
	second->prev = NULL;
	data->stack_a = second;
	data->operations++;
	print_list(data->stack_a, "Stack A After ra");
	print_list(data->stack_b, "Stack B After ra");
}

void rb(t_data *data)
{
	t_lst_indexed_node *last;
	t_lst_indexed_node *second;
	if (!data->stack_b || data->size_b < 2)
		return;
	last = ft_lsti_last(data->stack_b);
	second = data->stack_b->next;
	last->next = data->stack_b;
	data->stack_b->prev = last;
	data->stack_b->next = NULL;
	second->prev = NULL;
	data->stack_b = second;
	data->operations++;
	print_list(data->stack_a, "Stack A After rb");
	print_list(data->stack_b, "Stack B After rb");
}

void rr(t_data *data)
{
	ra(data);
	rb(data);
	data->operations++;
	print_list(data->stack_a, "Stack A After rr");
	print_list(data->stack_b, "Stack B After rr");
}

void rra(t_data *data)
{
	t_lst_indexed_node *last;
	t_lst_indexed_node *second_last;
	if (!data->stack_a || data->size_a < 2)
		return;
	last = ft_lsti_last(data->stack_a);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = data->stack_a;
	data->stack_a->prev = last;
	data->stack_a = last;
	data->operations++;
	print_list(data->stack_a, "Stack A After rra");
	print_list(data->stack_b, "Stack B After rra");
}
void rrb(t_data *data)
{
	t_lst_indexed_node *last;
	t_lst_indexed_node *second_last;
	if (!data->stack_b || data->size_b < 2)
		return;
	last = ft_lsti_last(data->stack_b);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = data->stack_b;
	data->stack_b->prev = last;
	data->stack_b = last;
	data->operations++;
	print_list(data->stack_a, "Stack A After rrb");
	print_list(data->stack_b, "Stack B After rrb");
}

void rrr(t_data *data)
{
	rra(data);
	rrb(data);
	data->operations++;
	print_list(data->stack_a, "Stack A After rrr");
	print_list(data->stack_b, "Stack B After rrr");
}
