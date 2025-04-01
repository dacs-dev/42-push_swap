/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:17:58 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/26 15:18:04 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstsort_int(int *lst, int size)
{
	int	wrapper;
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (lst[i] > lst[i + 1])
		{
			wrapper = lst[i];
			lst[i] = lst[i + 1];
			lst[i + 1] = wrapper;
			i = 0;
		}
		else
			i++;
	}
}
