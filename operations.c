/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:32:56 by dcid-san          #+#    #+#             */
/*   Updated: 2024/11/20 15:33:02 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void sa(t_data *data) {
    t_lst_indexed_node *first;
    t_lst_indexed_node *second;

    if (!data->stack_a || !data->stack_a->next)
        return; // Lista vacía o solo un elemento

    first = data->stack_a;
    second = first->next;

    // Actualizar enlaces
    first->next = second->next;
    if (second->next) // Si existe un tercer nodo
        second->next->prev = first;

    second->prev = NULL;
    second->next = first;
    first->prev = second;

    // Actualizar head del stack
    data->stack_a = second;
}

void sb(t_data *data) {
    t_lst_indexed_node *first;
    t_lst_indexed_node *second;

    if (!data->stack_b || !data->stack_b->next)
        return; // Lista vacía o solo un elemento

    first = data->stack_b;
    second = first->next;

    // Actualizar enlaces
    first->next = second->next;
    if (second->next) // Si existe un tercer nodo
        second->next->prev = first;

    second->prev = NULL;
    second->next = first;
    first->prev = second;

    // Actualizar head del stack
    data->stack_b = second;
}

void ss(t_data *data)
{
    sa(data);
    sb(data);
}

void pa(t_data *data)
{
    ft_lsti_addfront(&(data -> stack_a), data -> stack_b);
    ft_lsti_deletenode(&(data -> stack_b), data -> stack_b);
    data -> size_b--;
    data -> size_a++;
}
