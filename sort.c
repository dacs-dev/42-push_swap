# include "push_swap.h"


int	stack_len(t_lst_indexed_node *node)
{
	int	count;

	if (!node) 
		return (0);
	count = 0;
	while (node)
	{
		node = node->next;
		count++;
	}
	return (count);
}

void	set_cost_pa(t_lst_indexed_node *node_a, t_lst_indexed_node *node_b)
{
    int	len_a;
	int	len_b;

	len_a = stack_len(node_a);
	len_b = stack_len(node_b);
	while (node_a)
	{
		node_a->push_cost = node_a->index;
		if (!(node_a->above_median))
			node_a->push_cost = len_a - (node_a->index);
		if (node_a->target->above_median)
			node_a->push_cost += node_a->target->index;
		else
			node_a->push_cost += len_b - (node_a->target->index);
		node_a = node_a->next;
	}
    
}


void	ft_lsti_mark_cheap(t_lst_indexed_node *stack)
{
	long			cheapest_value;
	t_lst_indexed_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	prep_for_push(t_data *data,  t_lst_indexed_node *top_node, char stack_name)
{

		if (stack_name == 'a')
		{
			while (data->stack_a != top_node)
			{
				if (top_node->above_median)
					ra(data, 1);
				else
					rra(data, 1);
			}
		}
		else if (stack_name == 'b')
		{
			while (data->stack_b != top_node)
			{
				if (top_node->above_median)
					rb(data, 1);
				else
					rrb(data, 1);
			}
		}	
	
}

static void	set_target_a(t_lst_indexed_node *a, t_lst_indexed_node *b)//Find `a` node's target in stack `b`
{
	t_lst_indexed_node	*current_b;
	t_lst_indexed_node	*target_node;
	long			best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value 
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target = ft_lsti_find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}
static void	set_target_b(t_lst_indexed_node *a, t_lst_indexed_node *b)
{
	t_lst_indexed_node	*current_a;
	t_lst_indexed_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value 
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = ft_lsti_find_smallest(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void find_targets_b(t_lst_indexed_node *node_b, t_lst_indexed_node *node_a)
{
	t_lst_indexed_node	*temp_a;
	t_lst_indexed_node	*target;
	long				target_value;
	long				casted_value;

	while (node_b)
	{
		target_value = LONG_MAX;
		temp_a = node_a;
		while (temp_a)
		{
			casted_value = (long) temp_a -> value;
			if (temp_a ->value > node_b->value && casted_value < target_value)
			{
				target_value = casted_value;
				target = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (target_value == LONG_MAX)
			node_b->target = ft_lsti_find_smallest(node_a);
		else
			node_b->target = target;
		node_b = node_b->next;
	}
}

void	ft_lsti_refresh_index(t_lst_indexed_node *node)
{
	int	i;
	int	median;

	i = 0;
	if (!node)
		return ;
	median = stack_len(node) / 2;
	while (node)
	{
		node->index = i;
		if (i <= median)
			node->above_median = 1;
		else
			node->above_median = 0;
		node = node->next;
		++i;
	}
}



t_lst_indexed_node	*ft_lsti_find_cheap(t_lst_indexed_node *node)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);;
	
}



static void	rotate_both(t_data *data,
	t_lst_indexed_node *cheapest_node)
{
	while (data->stack_b != cheapest_node->target
	&& data->stack_a != cheapest_node)
		rr(data);
	ft_lsti_refresh_index(data->stack_a);
	ft_lsti_refresh_index(data->stack_b);
}

static void	rev_rotate_both(t_data *data,
	t_lst_indexed_node *cheapest_node)
{
	while (data->stack_b != cheapest_node->target
		&& data->stack_a != cheapest_node)
		rrr(data);
	ft_lsti_refresh_index(data->stack_a);
	ft_lsti_refresh_index(data->stack_b);
}

static void	move_a_to_b(t_data *data)
{
	t_lst_indexed_node	*best;

	best = ft_lsti_find_cheap(data->stack_a); 
	if (best->above_median 
		&& best->target->above_median)
		rotate_both(data, best);
	else if (!(best->above_median) 
		&& !(best->target->above_median))
		rev_rotate_both(data, best);
	prep_for_push(data, best, 'a');
	prep_for_push(data, best->target, 'b');
	pb(data);
}

static void	move_b_to_a(t_data *data)
{
	prep_for_push(data, data->stack_b->target, 'a');
	pa(data); 
}



static void	last_sort(t_data *data) 
{
	while ((data->stack_a)->value != ft_lsti_find_smallest(data->stack_a)->value) 
	{
		if (ft_lsti_find_smallest(data->stack_a)->above_median) 
			ra(data, 1);
		else
			rra(data, 1);
	}
}

void	refresh_stack_a(t_lst_indexed_node *a, t_lst_indexed_node *b)
{
	ft_lsti_refresh_index(a);
	ft_lsti_refresh_index(b);
	set_target_a(a, b);
	set_cost_pa(a, b);
	ft_lsti_mark_cheap(a);
}
void	refresh_stack_b(t_lst_indexed_node *a, t_lst_indexed_node *b)
{
	ft_lsti_refresh_index(a);
	ft_lsti_refresh_index(b);
	set_target_b(a, b);
}

void sort(t_data *data)
{
	int	len_a;

	len_a = stack_len(data->stack_a);
	if (len_a-- > 3 && !ft_lsti_is_sorted(data->stack_a))
		pb(data);
	if (len_a-- > 3 && !ft_lsti_is_sorted(data->stack_a))
		pb(data);
	while (len_a-- > 3 && !ft_lsti_is_sorted(data->stack_a))
	{
		refresh_stack_a(data->stack_a, data->stack_b);
		move_a_to_b(data);
	}
	sort_three(data);
	while (data->stack_b)
	{
		refresh_stack_b(data->stack_a, data->stack_b);
		move_b_to_a(data);
	}
	ft_lsti_refresh_index(data->stack_a);
	last_sort(data);
}
