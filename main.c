/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:36:53 by dcid-san          #+#    #+#             */
/*   Updated: 2024/11/20 15:44:50 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void    print_list(t_lst_indexed_node *stack, const char *stack_name) {
    t_lst_indexed_node *current;
    int position = 0;

    if (!stack) {
        printf("%s: (vacío)\n", stack_name);
        return;
    }

    current = stack;
    printf("═════ %s ═════\n", stack_name);
    printf("Pos │ Valor  │ Índice\n");

    // Para listas circulares: while (1) + break cuando vuelva al inicio
    // Para listas no circulares: while (current != NULL)
    while (current != NULL) { // Solo para listas lineales
            printf("%-3d │ %-6d │ %-6d\n", position++, current->value, current->index);
            current = current->next;
        } // Versión híbrida

    printf("═════════════════════\n\n");
}
void ft_free_split(char **arr) {
    char **tmp = arr;
    while (*tmp) {
        free(*tmp);
        tmp++;
    }
    free(arr);
}

int error_exit(t_data *data, char *msg, int msg_size){
    free_stack(data -> stack_a);
    free_stack(data -> stack_b);
    free(data);
    write(2, msg, msg_size);
    return (1);
}

t_lst_indexed_node  *parse_args(int argc, char **argv, t_data *data)
{
    int i;
    long number;
    unsigned long       size;
    char **arg_lst;
    char **tmp_arg_lst;

    i = 1;
    size = 0;
    while (i < argc)
    {
        arg_lst = ft_split(argv[i], ' ');
        if (!arg_lst)
            return(error_exit(data, "Error: Fallo al dividir argumentos\n", 35), NULL);
        tmp_arg_lst = arg_lst;
        while(*arg_lst)
        {
            printf("%s\n", *arg_lst);
            if (!str_isnum(*arg_lst))
                return (ft_free_split(tmp_arg_lst), error_exit(data, "Error: Se ha encontrado un carácter no numérico\n", 50),NULL);

            number = ft_atoi(*arg_lst);
            printf("%lu\n", number);
            if(number < INT_MIN || number > INT_MAX)
                return (ft_free_split(tmp_arg_lst), error_exit(data, "Error: Uno de los numeros introducidos excede del rango de int\n", 63),NULL);

            if (ft_lsti_find(data -> stack_a, number))
            {
                return (ft_free_split(tmp_arg_lst), error_exit(data, "Error: Se ha encontrado un valor duplicado\n", 43),NULL);
            }
            t_lst_indexed_node *new_node = ft_lsti_newnode((int)number);
            if (!new_node)
                return (ft_free_split(tmp_arg_lst),error_exit(data, "Error: Fallo de memoria\n", 24), NULL);


            ft_lsti_addback(&(data -> stack_a), new_node);
            arg_lst++;
            size++;
        }
        ft_free_split(tmp_arg_lst);
        i++;
    }
    data->size_a = size;
    return (data -> stack_a);
}

int main(int argc, char **argv)
{
    t_data              *data;

    data = malloc(sizeof(t_data));
    if(!data)
        return(error_exit(data, "Error: Insuficiencia de memoria para malloc\n", 45));
    data->stack_b = NULL;
    data->stack_a = NULL;
    if (argc < 2)
        return (error_exit(data, "Es necesario incluir 1 argumento por lo menos\n", 46));

    if (!parse_args(argc, argv, data))
        return (1);
    if(data -> stack_a)
        print_list(data -> stack_a, "Stack A");

    push_swap(data);

    free_stack(data -> stack_a);
    free_stack(data -> stack_b);
    free(data);
    return (0);
}
