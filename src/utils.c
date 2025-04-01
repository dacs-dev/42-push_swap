/* ************************************************************************** */
/*                                                                          */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-01 04:21:25 by dcid-san          #+#    #+#             */
/*   Updated: 2025-04-01 04:21:25 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_isnum(char *str)
{
	if (!str || !*str)
		return (0);
	if ((*str == '-' || *str == '+') && !*++str)
		return (0);
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

void	ft_free_split(char **arr)
{
	char	**tmp;

	if (arr != NULL)
	{
		tmp = arr;
		while (*tmp != NULL)
		{
			free(*tmp);
			tmp++;
		}
		free(arr);
	}
}

int	ft_lsti_is_sorted(t_lsti_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
