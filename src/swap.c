/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-01 03:24:39 by dcid-san          #+#    #+#             */
/*   Updated: 2025-04-01 03:24:39 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data, int show_msg)
{
	t_lsti_node	*first;
	t_lsti_node	*second;

	if (!data->stack_a || !data->stack_a->next)
		return ;
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
	if (show_msg)
		write(1, "sa\n", 3);
}

void	sb(t_data *data, int show_msg)
{
	t_lsti_node	*first;
	t_lsti_node	*second;

	if (!data->stack_b || !data->stack_b->next)
		return ;
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
	if (show_msg)
		write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	sa(data, 0);
	sb(data, 0);
	data->operations--;
	write(1, "ss\n", 3);
}
