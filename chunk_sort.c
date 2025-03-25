#include "push_swap.h"

void find_max_and_push(t_data *data)
{
	t_lst_indexed_node *current;
	int                 max_val = INT_MIN;
	int                 max_pos = 0;
	int                 i = 0;

	current = data->stack_b;
	// Encontrar posición y valor del máximo en B
	while (current)
	{
		if (current->value > max_val)
		{
			max_val = current->value;
			max_pos = i;
		}
		current = current->next;
		i++;
	}

	// Calcular rotaciones óptimas
	int moves_up = max_pos;                  // Rotaciones hacia arriba (rb)
	int moves_down = data->size_b - max_pos; // Rotaciones hacia abajo (rrb)

	// Ejecutar rotaciones
	if (moves_up <= moves_down)
	{
		for (int j = 0; j < moves_up; j++)
			rb(data);
	}
	else
	{
		for (int j = 0; j < moves_down; j++)
			rrb(data);
	}

	// Mover el máximo a A
	pa(data);
}

void chunk_sort(t_data *data)
{
	unsigned long chunk_size = data->size_a <= 100 ? 20 : 50;
	// unsigned long       total_elements = data->size_a;
	t_lst_indexed_node *current;
	// Asignar índices a los elementos (requiere implementación previa)
	assign_indices(data->stack_a);

	// Mover elementos a B por chunks
	unsigned long current_chunk = 1;
	while (data->size_a > 0)
	{
		current = data->stack_a;
		if (current->index <= (current_chunk * chunk_size))
		{
			pb(data);
		}
		else
		{
			ra(data);
		}
		// Actualizar chunk si se han movido suficientes elementos
		if (data->size_b == current_chunk * chunk_size)
		{
			current_chunk++;
		}
	}

	// Devolver elementos ordenados a A
	while (data->size_b)
	{
		find_max_and_push(data);
	}
}
