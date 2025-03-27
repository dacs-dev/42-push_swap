/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_atoi.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: krusty <krusty@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/09/17 18:15:22 by dcid-san		  #+#	#+#			 */
/*   Updated: 2025/03/27 15:21:24 by krusty		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

const char	*advance_spaces(const char *str)
{
	while (*str == ' ' || *str == '\f' || *str == '\t'
		|| *str == '\n' || *str == '\r' || *str == '\v')
		str++;
	return (str);
}

int	ft_atoi(const char *str)
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
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)(result * sign));
}
