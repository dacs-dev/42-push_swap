/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-01 04:26:07 by dcid-san          #+#    #+#             */
/*   Updated: 2025-04-01 04:26:07 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_data *data)
{
	int	first;
	int	second;

	first = data->stack_a->value;
	second = data->stack_a->next->value;
	if (first > second)
		sa(data, 1);
}

void	sort_three(t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = data->stack_a->value;
	second = data->stack_a->next->value;
	third = data->stack_a->next->next->value;
	if (first > second && second < third && first < third)
		sa(data, 1);
	else if (first > second && second < third && first > third)
		ra(data, 1);
	else if (first > second && second > third)
	{
		sa(data, 1);
		rra(data, 1);
	}
	else if (first < second && second > third && first < third)
	{
		sa(data, 1);
		ra(data, 1);
	}
	else if (first < second && second > third && first > third)
		rra(data, 1);
}

void	sort_small_list(t_data *data)
{
	if (data->size_a == 2)
		sort_two(data);
	else if (data->size_a == 3)
		sort_three(data);
}

void	push_swap(t_data *data)
{
	if (data->size_a > 1 && data -> size_a < 4)
	{
		sort_small_list(data);
	}
	else if (data -> size_a > 3)
		sort(data);
}
