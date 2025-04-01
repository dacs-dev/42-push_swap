/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-01 03:26:53 by dcid-san          #+#    #+#             */
/*   Updated: 2025-04-01 03:26:53 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data, int show_msg)
{
	t_lsti_node	*last;
	t_lsti_node	*second;

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
	if (show_msg)
		write(1, "ra\n", 3);
}

void	rb(t_data *data, int show_msg)
{
	t_lsti_node	*last;
	t_lsti_node	*second;

	if (!data->stack_b || data->size_b < 2)
		return ;
	last = ft_lsti_last(data->stack_b);
	second = data->stack_b->next;
	last->next = data->stack_b;
	data->stack_b->prev = last;
	data->stack_b->next = NULL;
	second->prev = NULL;
	data->stack_b = second;
	data->operations++;
	if (show_msg)
		write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	ra(data, 0);
	rb(data, 0);
	data->operations--;
	write(1, "rr\n", 3);
}
