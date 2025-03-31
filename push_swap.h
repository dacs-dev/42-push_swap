/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:33:04 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/31 05:03:56 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h" /* Se asume que usas funciones de la libft */
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define ROTATE 1
# define REVERSE_ROTATE 2
# define RB 3
# define RRB 4
# define SA 5
# define SB 6

# define NAN_ERR "Error\n"
# define DUP_ERR "Error\n"
# define LIMIT_ERR "Error\n"
# define MALLOC_ERR "Error\n"
# define ARG_ERR "Error\n"

# define NAN_ERR_BACK "Error\nSe ha encontrado un carácter no numérico\n"
# define DUP_ERR_BACK "Error\nSe ha encontrado un valor duplicado\n"
# define LIMIT_ERR_BACK "Error\nRango de int excedido\n"
# define MALLOC_ERR_BACK "Error\nFallo de memoria\n"
# define ARG_ERR_BACK "Error\nEs necesario incluir 1 argumento por lo menos\n"

typedef struct s_cost {
    int cost_a;
    int cost_b;
    int total_cost;
    int direction_a;
    int direction_b; 
} t_cost;

typedef struct s_lst_indexed_node
{
	int							value;
	unsigned int				index;
	unsigned int				push_cost;
	int							best_move;
	int							above_median;
	struct s_lst_indexed_node	*target;
	int							cheapest;
	struct s_lst_indexed_node	*next;
	struct s_lst_indexed_node	*prev;
}	t_lst_indexed_node;

/*
** Estructura de la pila.
** Contiene el puntero al primer nodo (tope de la pila) y el tamaño de la pila.
*/

typedef struct s_data
{
	t_lst_indexed_node	*stack_a;
	t_lst_indexed_node	*stack_b;
	unsigned int		size_a;
	unsigned int		size_b;
	unsigned int		min_b;
	unsigned int		max_b;
	unsigned int		min_a;
	unsigned int		max_a;
	int					operations;
}	t_data;

// Funciones de utilidad para las listas
t_lst_indexed_node	*ft_lsti_newnode(int value);
t_lst_indexed_node	*ft_lsti_addback(t_lst_indexed_node **start,
						t_lst_indexed_node *node);
t_lst_indexed_node	*ft_lsti_addfront(t_lst_indexed_node **start,
						t_lst_indexed_node *node);
t_lst_indexed_node	*ft_lsti_last(t_lst_indexed_node *lst);
int					ft_lsti_find(t_lst_indexed_node *node, int num);
void				free_stack(t_lst_indexed_node *stack);
void				print_list(t_lst_indexed_node *stack,
	const char *stack_name);
void				ft_lsti_deletenode(t_lst_indexed_node **head,
					t_lst_indexed_node *node);
t_lst_indexed_node	*ft_lsti_find_max(t_lst_indexed_node *stack);
t_lst_indexed_node	*ft_lsti_find_smallest(t_lst_indexed_node *node);
int					ft_lsti_is_sorted(t_lst_indexed_node *stack);
void 				sort_three(t_data *data);

// Funcion para parsear los argumentos del programa
t_lst_indexed_node	*parse_args(int argc, char **argv, t_data *data);
void				sa(t_data *data, int show_msg);
void				sb(t_data *data, int show_msg);
void				ss(t_data *data);
void				pa(t_data *data);
void				pb(t_data *data);
void				ra(t_data *data, int show_msg);
void				rb(t_data *data, int show_msg);
void				rr(t_data *data);
void				rra(t_data *data, int show_msg);
void				rrb(t_data *data, int show_msg);
void				rrr(t_data *data);

void				assign_indices(t_data *data);
void				k_sort(t_data *data, unsigned int k);
unsigned int		calc_chunkn(unsigned int size);
void				push_swap(t_data *data);
void error_exit(t_data *data, char *msg, int msg_size, char** split);
void radix_sort(t_data *data);
void sort(t_data *data);

// Utilidades
int					str_isnum(char *str);
void				ft_free_split(char **arr);

#endif
