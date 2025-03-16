/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:33:04 by dcid-san          #+#    #+#             */
/*   Updated: 2024/11/20 15:44:09 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft/libft.h" /* Se asume que usas funciones de la libft */

/*
** Estructura del nodo de la pila.
** Cada nodo contiene el valor, un índice (para el orden final) y el puntero al
** siguiente nodo.
*/
typedef struct s_lst_indexed_node
{
	int    value;
	int    index; /* Inicialmente se asigna -1; se actualizará en assign_indices */
	struct s_lst_indexed_node *next;
	struct s_lst_indexed_node *prev;
} t_lst_indexed_node;

/*
** Estructura de la pila.
** Contiene el puntero al primer nodo (tope de la pila) y el tamaño de la pila.
*/

typedef struct s_data
{
    t_lst_indexed_node *stack_a;       // Puntero al primer nodo del stack A
    t_lst_indexed_node *stack_b;       // Puntero al primer nodo del stack B
    unsigned long       size_a;         // Tamaño actual del stack A
    unsigned long       size_b;         // Tamaño actual del stack B
    int                 min_value;      // Valor mínimo del stack (opcional, para optimización)
    int                 max_value;      // Valor máximo del stack (opcional, para optimización)
} t_data;


// Funciones de utilidad para las listas
t_lst_indexed_node *ft_lsti_newnode(int value);
t_lst_indexed_node *ft_lsti_addback(t_lst_indexed_node **start, t_lst_indexed_node *node);
t_lst_indexed_node *ft_lsti_addfront(t_lst_indexed_node **start, t_lst_indexed_node *node);
t_lst_indexed_node *ft_lsti_last(t_lst_indexed_node *lst);
int                 ft_lsti_find(t_lst_indexed_node *node, int num);
void                free_stack(t_lst_indexed_node *stack);
void                print_list(t_lst_indexed_node *stack, const char *stack_name);
void ft_lsti_deletenode(t_lst_indexed_node **head, t_lst_indexed_node *node);

// Funcion para parsear los argumentos del programa
t_lst_indexed_node  *parse_args(int argc, char **argv, t_data *data);


/* Libera todos los nodos de la pila y la estructura de la pila.
   Recibe un puntero al puntero de la pila para establecerlo a NULL tras liberar. */

/*
** Prototipos de las operaciones básicas de la pila.
**
** Las operaciones deben escribir la instrucción en la salida estándar para el checker.
*/
void sa(t_data *data);
void sb(t_data *data);
void ss(t_data *data);
void pa(t_data *data);
void pb(t_data *data);
void ra(t_data *data);
void rb(t_data *data);
void rr(t_data *data);
void rra(t_data *data);
void rrb(t_data *data);
void rrr(t_data *data);

//Utilidades
int str_isnum(char *str);


/* Asigna un índice a cada nodo según su posición en el orden ascendente.
   Por ejemplo, el valor más pequeño recibe índice 0, el siguiente 1, etc. */
void assign_indices(t_lst_indexed_node *stack);

/* Función principal que determina y ejecuta la secuencia de operaciones
   para ordenar la pila A utilizando la pila B auxiliar. */
void push_swap(t_data *data);

#endif
