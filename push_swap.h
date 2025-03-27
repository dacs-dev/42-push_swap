/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:33:04 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/27 15:30:13 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h" /* Se asume que usas funciones de la libft */
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define RA 1
# define RRA 2

typedef struct s_lst_indexed_node
{
	int			value;
	unsigned	long index;
	struct s_lst_indexed_node *next;
	struct s_lst_indexed_node *prev;
} t_lst_indexed_node;

/*
** Estructura de la pila.
** Contiene el puntero al primer nodo (tope de la pila) y el tamaño de la pila.
*/

typedef struct s_data
{
	t_lst_indexed_node	*stack_a;
	t_lst_indexed_node	*stack_b;
	unsigned long		size_a;
	unsigned long		size_b;
	int					min_value;
	int					max_value;
	int					operations;
}	t_data;

// Funciones de utilidad para las listas
t_lst_indexed_node *ft_lsti_newnode(int value);
t_lst_indexed_node *ft_lsti_addback(t_lst_indexed_node **start, t_lst_indexed_node *node);
t_lst_indexed_node *ft_lsti_addfront(t_lst_indexed_node **start, t_lst_indexed_node *node);
t_lst_indexed_node *ft_lsti_last(t_lst_indexed_node *lst);
int                 ft_lsti_find(t_lst_indexed_node *node, int num);
void                free_stack(t_lst_indexed_node *stack);
void print_list(t_lst_indexed_node *stack, const char *stack_name);
void ft_lsti_deletenode(t_lst_indexed_node **head, t_lst_indexed_node *node);
int  ft_lsti_find_smallest(t_lst_indexed_node *node);

// Funcion para parsear los argumentos del programa
t_lst_indexed_node	*parse_args(int argc, char **argv, t_data *data);

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

// Utilidades
int str_isnum(char *str);

/* Asigna un índice a cada nodo según su posición en el orden ascendente.
   Por ejemplo, el valor más pequeño recibe índice 0, el siguiente 1, etc. */
void assign_indices(t_data *data);

/* Función principal que determina y ejecuta la secuencia de operaciones
   para ordenar la pila A utilizando la pila B auxiliar. */
void push_swap(t_data *data);
int  error_exit(t_data *data, char *msg, int msg_size);

#endif
