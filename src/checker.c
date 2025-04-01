/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-01 05:09:01 by dcid-san          #+#    #+#             */
/*   Updated: 2025-04-01 05:09:01 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_arg_lst(t_data *data, char **arg_lst, unsigned int *size)
{
	long		number;
	char		**tmp_arg_lst;
	t_lsti_node	*new_node;

	tmp_arg_lst = arg_lst;
	while (*arg_lst)
	{
		if (!str_isnum(*arg_lst))
			error_exit(data, NAN_ERR, 50, tmp_arg_lst);
		number = ft_atol(*arg_lst);
		if (number < INT_MIN || number > INT_MAX)
			error_exit(data, LIMIT_ERR, 29, tmp_arg_lst);
		if (ft_lsti_find(data->stack_a, (int)number))
			error_exit(data, DUP_ERR, 43, tmp_arg_lst);
		new_node = ft_lsti_newnode((int) number);
		if (!new_node)
			error_exit(data, MALLOC_ERR, 24, tmp_arg_lst);
		new_node->index = *size;
		ft_lsti_addback(&(data->stack_a), new_node);
		arg_lst++;
		*size = *size + 1;
	}
	ft_free_split(tmp_arg_lst);
}

t_lsti_node	*parse_args(int argc, char **argv, t_data *data)
{
	int				i;
	unsigned int	size;
	char			**arg_lst;

	i = 1;
	size = 0;
	while (i < argc)
	{
		if (argv[i][0] != '\0')
		{
			arg_lst = ft_split(argv[i], ' ');
			if (!arg_lst)
				error_exit(data, "Error\n", 6, NULL);
			check_arg_lst(data, arg_lst, &size);
		}
		else
			error_exit(data, "Error\n", 6, NULL);
		i++;
	}
	data->size_a = size;
	return (data->stack_a);
}

int	process_ops(t_data *data)
{
	char	*line;
	char	*trimmed;

	while (1)
	{
		line = get_next_line(0);
		if (!line || line[0] == '\n')
			break ;
		trimmed = ft_strtrim(line, "\n");
		free(line);
		if (!is_valid_op(trimmed))
		{
			free(trimmed);
			return (0);
		}
		execute_op(data, trimmed);
		free(trimmed);
	}
	if (line != NULL)
		free(line);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (argc == 1)
		return (free(data), 0);
	ft_bzero(data, sizeof(t_data));
	if (!parse_args(argc, argv, data))
	{
		error_exit(data, "Error\n", 6, NULL);
		return (1);
	}
	if (!process_ops(data))
	{
		error_exit(data, "Error\n", 6, NULL);
		return (1);
	}
	check_result(data);
	free_stack(data->stack_a);
	free_stack(data->stack_b);
	free(data);
	return (0);
}
