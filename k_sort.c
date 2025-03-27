#include "push_swap.h"

int	calc_rotate_direction(t_data *data, unsigned index)
{
	unsigned			position;
	t_lst_indexed_node	*current;

	current = data->stack_a;
	position = 0;
	while (current != NULL)
	{
		position++;
		if (current->index == index)
			break ;
		current = current->next;
	}
	if (position <= data->size_a / 2)
		return (RA);
	else
		return (RRA);
}

int calc_chunkn(unsigned long size)
{
	if (size <= 100)
		return (5);
	else if (size <= 500)
		return (10);
	else
		return (25);
}

void	k_sort(t_data *data, int k)
{
	unsigned	chunk_size;
	unsigned	min_index;
	unsigned	max_index;
	unsigned	i;
	t_lst_indexed_node	*current;

	i = k;
	chunk_size = data -> size_a / k;
	while (i > 0)
	{
		min_index = i * chunk_size;
		max_index = (i +1 * chunk_size) - 1;
		while (min_index <= max_index)
		{	
			if (calc_rotate_direction(data, min_index) == RA)
			{
				
			}
			else
			{
				/* code */
			}
			
			min_index++
		}
		
		i--;
	}
	
}
