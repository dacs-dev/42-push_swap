#include "push_swap.h"

void sort_two(t_data *data)
{
	int first;
	int second;

	first = data->stack_a->value;
	second = data->stack_a->next->value;
	if (first > second)
		sa(data);
}

void sort_three(t_data *data)
{
	int first;
	int second;
	int third;

	first = data->stack_a->value;
	second = data->stack_a->next->value;
	third = data->stack_a->next->next->value;
	// Caso: 2 1 3
	if (first > second && second < third && first < third)
		sa(data);
	// Caso: 3 1 2
	else if (first > second && second < third && first > third)
		ra(data);
	// Caso: 3 2 1
	else if (first > second && second > third)
	{
		sa(data);
		rra(data);
	}
	// Caso: 1 3 2
	else if (first < second && second > third && first < third)
	{
		sa(data);
		ra(data);
	}
	// Caso: 2 3 1
	else if (first < second && second > third && first > third)
		rra(data);
}
void sort_four_five(t_data *data)
{
	// Mover los 2 menores a B
	while (data->size_a > 3)
	{
		if (data->stack_a->value == ft_lsti_find_smallest(data->stack_a))
			pb(data);
		else
			ra(data);
	}
	sort_three(data); // Ordenar los 3 restantes en A
	while (data->stack_b)
		pa(data); // Devolver elementos
}
void sort_small_list(t_data *data)
{
	if (data->size_a == 2)
		sort_two(data);
	else if (data->size_a == 3)
		sort_three(data);
	else if (data->size_a <= 5)
		sort_four_five(data);
}
void push_swap(t_data *data)
{
	if (data->size_a > 1)
	{
		sort_small_list(data);
	}
}
