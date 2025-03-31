/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:32:56 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/31 03:47:59 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void sa(t_data *data, int show_msg)
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
	//print_list(data->stack_a, "Stack A After sa\n");
	//print_list(data->stack_b, "Stack B After sa\n");
	if (show_msg)
		write(1, "sa\n", 3);
}

void sb(t_data *data, int show_msg)
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
	//print_list(data->stack_a, "Stack A After sb\n");
	//print_list(data->stack_b, "Stack B After sb\n");
	if (show_msg)
		write(1, "sb\n", 3);

}

void ss(t_data *data)
{
	sa(data, 0);
	sb(data, 0);
	data->operations--;
	//print_list(data->stack_a, "Stack A After ss\n");
	//print_list(data->stack_b, "Stack B After ss\n");
	write(1, "ss\n", 3);
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

		write(1, "pa\n", 3);
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
        to_move->next = NULL; // Ensure the node is detached
        ft_lsti_addfront(&(data->stack_b), to_move);
        data->size_a--;
        data->size_b++;
        data->operations++;
        write(1, "pb\n", 3);

	}
}

void ra(t_data *data, int show_msg)
{
	t_lst_indexed_node *last;
	t_lst_indexed_node *second;

	if (!data->stack_a || data->size_a < 2)
		return ;
	last = ft_lsti_last(data->stack_a);
	second = data->stack_a->next;
	last->next = data->stack_a;
	data->stack_a->prev = last;
	data->stack_a->next = NULL;
	second->prev = NULL;
	data->stack_a = second;
	data->operations++;
	//print_list(data->stack_a, "Stack A After ra\n");
	//print_list(data->stack_b, "Stack B After ra\n");
	if (show_msg)
		write(1, "ra\n", 3);

}

void rb(t_data *data, int show_msg)
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
	//print_list(data->stack_a, "Stack A After rb\n");
	//print_list(data->stack_b, "Stack B After rb\n");
	if (show_msg)
		write(1, "rb\n", 3);

}

void rr(t_data *data)
{
	ra(data, 0);
	rb(data, 0);
	data->operations--;
	//print_list(data->stack_a, "Stack A After rr\n");
	//print_list(data->stack_b, "Stack B After rr\n");
	write(1, "rr\n", 3);
}

void rra(t_data *data, int show_msg)
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
	//print_list(data->stack_a, "Stack A After rra\n");
	//print_list(data->stack_b, "Stack B After rra\n");
	if (show_msg)
		write(1, "rra\n", 4);
}
void rrb(t_data *data, int show_msg)
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
	//print_list(data->stack_a, "Stack A After rrb\n");
	//print_list(data->stack_b, "Stack B After rrb\n");
	if (show_msg)
		write(1, "rrb\n", 4);
}

void rrr(t_data *data)
{
	rra(data, 0);
	rrb(data, 0);
	data->operations--;
	//print_list(data->stack_a, "Stack A After rrr\n");
	//print_list(data->stack_b, "Stack B After rrr\n");
	write(1, "rrr\n", 4);
}
