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

typedef struct s_cost
{
	int	cost_a;
	int	cost_b;
	int	total_cost;
	int	direction_a;
	int	direction_b;
}	t_cost;

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
}	t_lsti_node;

/*
** Estructura de la pila.
** Contiene el puntero al primer nodo (tope de la pila) y el tamaño de la pila.
*/

typedef struct s_data
{
	t_lsti_node		*stack_a;
	t_lsti_node		*stack_b;
	unsigned int	size_a;
	unsigned int	size_b;
	unsigned int	min_b;
	unsigned int	max_b;
	unsigned int	min_a;
	unsigned int	max_a;
	int				operations;
}	t_data;

t_lsti_node	*ft_lsti_newnode(int value);
t_lsti_node	*ft_lsti_addback(t_lsti_node **start,
				t_lsti_node *node);
t_lsti_node	*ft_lsti_addfront(t_lsti_node **start,
				t_lsti_node *node);
t_lsti_node	*ft_lsti_last(t_lsti_node *lst);
int			ft_lsti_find(t_lsti_node *node, int num);
void		free_stack(t_lsti_node *stack);

//void		print_list(t_lsti_node *stack,
//				const char *stack_name);

void		ft_lsti_deletenode(t_lsti_node **head,
				t_lsti_node *node);
t_lsti_node	*ft_lsti_find_max(t_lsti_node *stack);
t_lsti_node	*ft_lsti_find_smallest(t_lsti_node *node);
int			ft_lsti_is_sorted(t_lsti_node *stack);
int			ft_lsti_len(t_lsti_node *node);
void		ft_lsti_mark_cheap(t_lsti_node *stack);
t_lsti_node	*ft_lsti_find_cheap(t_lsti_node *node);

void		set_cost_pa(t_lsti_node *node_a, t_lsti_node *node_b);
void		set_target_a(t_lsti_node *stack_a, t_lsti_node *stack_b);
void		set_target_b(t_lsti_node *stack_a, t_lsti_node *stack_b);
t_lsti_node	*parse_args(int argc, char **argv, t_data *data);
void		sa(t_data *data, int show_msg);
void		sb(t_data *data, int show_msg);
void		ss(t_data *data);
void		pa(t_data *data);
void		pb(t_data *data);
void		ra(t_data *data, int show_msg);
void		rb(t_data *data, int show_msg);
void		rr(t_data *data);
void		rra(t_data *data, int show_msg);
void		rrb(t_data *data, int show_msg);
void		rrr(t_data *data);
void		op_both_stacks(t_data *data,
				t_lsti_node *cheapest_node,
				void (*op)(t_data *));
void		ft_lsti_refresh_index(t_lsti_node *node);
void		refresh_stack_a(t_lsti_node *stack_a, t_lsti_node *stack_b);
void		refresh_stack_b(t_lsti_node *stack_a, t_lsti_node *stack_b);
void		move_top(t_data *data,
				t_lsti_node *top_node, char stack_name);
void		error_exit(t_data *data, char *msg,
				int msg_size, char **split);
void		sort(t_data *data);
void		sort_three(t_data *data);
void		push_swap(t_data *data);
// Utilidad
int			str_isnum(char *str);
void		ft_free_split(char **arr);

#endif
