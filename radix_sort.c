#include "push_swap.h"

// void assign_indices(t_lst_indexed *lst)
// {
//     int *values;
//     t_lst_indexed_node *current;
//     int i;
//     int *found;

//     if (!lst || lst->size <= 0)
//         return;

//     values = malloc(sizeof(int) * lst->size);
//     if (!values)
//         return;

//     /* Copiamos los valores de la lista al arreglo */
//     current = lst->top;
//     i = 0;
//     while (current)
//     {
//         values[i++] = current->value;
//         current = current->next;
//     }

//     /* Ordenamos el arreglo */
//     qsort(values, lst->size, sizeof(int), cmp_int);

//     /* Asignamos a cada nodo su índice según el arreglo ordenado */
//     current = lst->top;
//     while (current)
//     {
//         found = bsearch(&current->value, values, lst->size, sizeof(int), cmp_int);
//         if (found)
//             current->index = (int)(found - values);
//         current = current->next;
//     }

//     free(values);
// }
