/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:15:22 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/27 15:29:41 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

char	*advance_spaces(const char *str)
{
	while (*str == ' ' || *str == '\f' || *str == '\t'
		|| *str == '\n' || *str == '\r' || *str == '\v')
		str++;
	return (str);
}

int	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	str = advance_spaces(str);
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > (LONG_MAX / 10) || (result == (LONG_MAX / 10)
				&& (*str - '0') > (LONG_MAX % 10)))
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

