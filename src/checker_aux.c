/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-01 05:25:59 by dcid-san          #+#    #+#             */
/*   Updated: 2025-04-01 05:25:59 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_valid_op(const char *line)
{
	if (!ft_strncmp(line, "sa", 3) || !ft_strncmp(line, "sb", 3)
		|| !ft_strncmp(line, "ss", 3) || !ft_strncmp(line, "pa", 3)
		|| !ft_strncmp(line, "pb", 3) || !ft_strncmp(line, "ra", 3)
		|| !ft_strncmp(line, "rb", 3) || !ft_strncmp(line, "rr", 3)
		|| !ft_strncmp(line, "rra", 4) || !ft_strncmp(line, "rrb", 4)
		|| !ft_strncmp(line, "rrr", 4))
		return (1);
	return (0);
}

void	error_exit(t_data *data, char *msg, int msg_size, char **split)
{
	(void) *msg;
	(void) msg_size;
	ft_free_split(split);
	free_stack(data->stack_a);
	free_stack(data->stack_b);
	free(data);
	if (msg != NULL)
		write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

void	check_result(t_data *data)
{
	if (ft_lsti_is_sorted(data->stack_a) && !data->stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	execute_op(t_data *data, const char *line)
{
	if (ft_strncmp(line, "sa", 3) == 0)
		sa(data, 0);
	else if (ft_strncmp(line, "sb", 3) == 0)
		sb(data, 0);
	else if (ft_strncmp(line, "ss", 3) == 0)
		ss(data);
	else if (ft_strncmp(line, "pa", 3) == 0)
		pa(data);
	else if (ft_strncmp(line, "pb", 3) == 0)
		pb(data);
	else if (ft_strncmp(line, "ra", 3) == 0)
		ra(data, 0);
	else if (ft_strncmp(line, "rb", 3) == 0)
		rb(data, 0);
	else if (ft_strncmp(line, "rr", 3) == 0)
		rr(data);
	else if (ft_strncmp(line, "rra", 4) == 0)
		rra(data, 0);
	else if (ft_strncmp(line, "rrb", 4) == 0)
		rrb(data, 0);
	else if (ft_strncmp(line, "rrr", 4) == 0)
		rrr(data);
}
