#include "push_swap.h"

// Supón que tienes funciones auxiliares:
// - get_position(stack, index): retorna la posición del nodo con ese índice en la pila.
// - get_insertion_position(stack_b, index): retorna la posición donde el nodo con ese índice debe insertarse en B.

unsigned int find_max_index(t_lst_indexed_node *stack)
{
    unsigned int max;
    t_lst_indexed_node *current;

    if (!stack)
        return (0);
    max = stack->index;
    current = stack;
    while (current != NULL)
    {
        //printf("[find_max_index] revisando nodo con index: %u\n", current->index);
        if (current->index > max)
            max = current->index;
        current = current->next;
    }
    //printf("[find_max_index] max encontrado: %u\n", max);
    return max;
}


int calc_rotate_direction_b(t_data *data, unsigned int index)
{
    unsigned int position;
    t_lst_indexed_node *current;

    current = data->stack_b;
    position = 0;
    while (current != NULL)
    {
        position++;
        if (current->index == index)
            break;
        current = current->next;
    }
    if (position <= data->size_b / 2)
        return RB;
    else
        return RRB;
}

unsigned int	get_insertion_position(t_lst_indexed_node *stack_b, unsigned int index)
{
	t_lst_indexed_node	*current;
	unsigned int					pos;
	unsigned int					max_pos;
	unsigned int		max_index;
	unsigned int		min_index;

	// Si la pila B está vacía, la inserción será en la posición 0.
	if (!stack_b)
		return (0);
	
	// Inicializamos valores con el primer nodo de B.
	current = stack_b;
	pos = 0;
	max_index = current->index;
	min_index = current->index;
	max_pos = 0;
	
	// Recorremos toda la pila B para obtener el máximo, el mínimo y la posición del máximo.
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = pos;
		}
		if (current->index < min_index)
			min_index = current->index;
		pos++;
		current = current->next;
	}
	
	// Si el índice a insertar es mayor que el máximo o menor que el mínimo,
	// se inserta después del nodo con el máximo (es decir, en la posición max_pos).
	if (index > max_index || index < min_index)
		return (max_pos);
	
	// De lo contrario, buscamos el lugar intermedio adecuado.
	// La pila B está ordenada de forma descendente:
	// buscamos dos nodos consecutivos donde el nodo actual tenga un índice mayor a 'index'
	// y el siguiente, un índice menor. En ese caso, 'index' encaja entre ellos.
	current = stack_b;
	pos = 0;
	while (current->next)
	{
		if (current->index > index && current->next->index < index)
			return (pos + 1);
		pos++;
		current = current->next;
	}
	// Si no se encontró una posición intermedia (caso poco probable), se retorna 0.
	return (0);
}

t_cost compute_cost(t_data *data, t_lst_indexed_node *node, unsigned int original_size) {
	t_cost cost;
	unsigned int pos_a = ft_lsti_find_index(data -> stack_a, node->index);
	
	// Calcular costo para mover el nodo en A
	if (pos_a <= original_size / 2) {
		cost.cost_a = pos_a;
		cost.direction_a = RA;
	} else {
		cost.cost_a = original_size - pos_a;
		cost.direction_a = RRA;
	}
	unsigned int pos_b = get_insertion_position(data->stack_b, node->index);
	// Calcular costo para posicionarlo correctamente en B
	if (pos_b <= data->size_b / 2)
	{
		cost.cost_b = pos_b;
		cost.direction_b = RB;
	} else
	{
		cost.cost_b = data->size_b - pos_b;
		cost.direction_b = RRB;
	}
	cost.total_cost = cost.cost_a + cost.cost_b;
	return cost;
}

void	move_chunk_a(t_data *data)
{
	unsigned int max_index;
	int rotate_type;

	while (data->stack_b != NULL)
	{
		max_index = find_max_index(data->stack_b);
		rotate_type = calc_rotate_direction_b(data, max_index);
		while (data->stack_b->index != max_index)
		{
			if (rotate_type == RB)
				rb(data, 1);
			else
				rrb(data, 1);
		}
		pa(data);
	}
}

void execute_optimal_move(t_data *data, t_cost cost) {
	// Si ambos movimientos son en la misma dirección, se pueden combinar.
	while (cost.cost_a > 0 && cost.cost_b > 0 && cost.direction_a == cost.direction_b) {
		if (cost.direction_a == RA)
			rr(data);
		else
			rrr(data);
		cost.cost_a--;
		cost.cost_b--;
	}

	// Rotaciones restantes en A
	while (cost.cost_a-- > 0) {
		if (cost.direction_a == RA)
			ra(data, 1);
		else
			rra(data, 1);
	}

	// Rotaciones restantes en B
	while (cost.cost_b-- > 0) {
		if (cost.direction_b == RB)
			rb(data, 1);
		else
			rrb(data, 1);
	}

	// Inserción directa en la posición óptima de B
	pb(data);
}


void process_chunk(t_data *data, unsigned int min_index, unsigned int max_index, unsigned int original_size) {
	t_lst_indexed_node *current = data->stack_a;
	t_cost best_cost;
	t_lst_indexed_node *best_node = NULL;
	best_cost.total_cost = INT_MAX; // Inicializamos con un valor alto

	// Recorremos la pila A para encontrar el elemento del chunk actual
	// con el menor costo para moverlo.
	while (current) {
		if (current->index >= min_index && current->index <= max_index) {
			t_cost cost = compute_cost(data, current, original_size);
			if (cost.total_cost < best_cost.total_cost) {
				best_cost = cost;
				best_node = current;
			}
		}
		current = current->next;
	}
	if (best_node)
		execute_optimal_move(data, best_cost);
}

int	is_chunk_on_a(t_lst_indexed_node *node, unsigned int min_index,
	unsigned int max_index)
{
while (node)
{
	if (node->index >= min_index && node ->index <= max_index)
		return (1);
	node = node-> next;
}
return (0);
}

void process_chunk_optimized(t_data *data, unsigned int min_index, unsigned int max_index)
{
    while (is_chunk_on_a(data->stack_a, min_index, max_index))
    {
        if (data->stack_a->index >= min_index && data->stack_a->index <= max_index)
        {
            pb(data);
            if (data->stack_b->index < (min_index + max_index) / 2)
                rb(data, 1);  // empuja abajo los pequeños
        }
        else
            ra(data, 1);
    }
}
unsigned int ft_sqrt(unsigned int n)
{
    unsigned int x = n;
    unsigned int y = 1;

    // Se itera hasta que la diferencia entre x e y sea mínima.
    while (x > y)
    {
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
}

unsigned int	calc_chunkn(unsigned int size)
{
	if (size <= 10)
		return (2);
	else if (size <= 100)
		return (5);
	else if (size <= 500)
		return (10);
	else
		return (25);
}




void final_sort(t_data *data, unsigned int original_size)
{
    t_lst_indexed_node *current;
    int min_pos;
    int pos;

    if (!data->stack_a)
        return;
    current = data->stack_a;
    min_pos = 0;
    pos = 0;
    // Buscamos la posición del nodo con índice 0
    while (current)
    {
        if (current->index == 0)
        {
            min_pos = pos;
            break;
        }
        pos++;
        current = current->next;
    }
    // Si el nodo con índice 0 no está en la cima, rotamos hasta que lo esté.
    if (min_pos <= (int)(original_size / 2))
    {
        while (min_pos-- > 0)
            ra(data, 1);
    }
    else
    {
        int moves = original_size - min_pos;
        while (moves-- > 0)
            rra(data, 1);
    }
}

void k_sort(t_data *data, unsigned int k)
{
    unsigned int chunk_size;
    unsigned int min_index;
    unsigned int max_index;
    unsigned int i;
    unsigned int original_size;

	original_size = data->size_a;
    i = 0;
    chunk_size = (original_size + k - 1) / k;
	while (i < k)
	{
		min_index = i * chunk_size;
		max_index = min_index + chunk_size - 1;
		if (max_index >= original_size)
			max_index = original_size - 1;

		
		// Mientras queden elementos en stack_a dentro del rango del chunk, procesa uno a uno.
		//printf("Nº [%u] max [%u] min [%u]\n",i ,max_index ,min_index);
		while (is_chunk_on_a(data->stack_a, min_index, max_index))
		{
			//printf("Chunk Processed:\n");
			process_chunk_optimized(data, min_index, max_index);
			//print_list(data->stack_a, "Stack A After chunk");
			//print_list(data->stack_b, "Stack B After chunk");
		}
		i++;
	}
	
	
    // Después de procesar todos los chunks, reinsertas los elementos en stack_a
    move_chunk_a(data);
	// print_list(data->stack_a, "Stack, A");
	// print_list(data->stack_a, "Stack, A");
	final_sort(data, original_size);
}

	