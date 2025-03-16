/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:15:22 by dcid-san          #+#    #+#             */
/*   Updated: 2024/09/25 20:03:57 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long ft_atoi(const char *str)
{
    long atoi_num;
    int is_neg;

    is_neg = 1;
    atoi_num = 0;
    while (*str == ' ' || *str == '\f' || *str == '\t' || *str == '\n' || *str == '\r' || *str == '\v')
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            is_neg = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        atoi_num = atoi_num * 10 + (*str - '0');
        str++;
    }
    return (atoi_num * is_neg);
}
