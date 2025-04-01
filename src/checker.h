/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-01 04:54:03 by dcid-san          #+#    #+#             */
/*   Updated: 2025-04-01 04:54:03 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

void	error_exit(t_data *data, char *msg, int msg_size, char **split);
void	check_result(t_data *data);
void	execute_op(t_data *data, const char *line);
int		is_valid_op(const char *line);

#endif