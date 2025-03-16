#include "push_swap.h"

void sort_small_list(t_data *data)
{
    t_lst_indexed_node *node_a;
    t_lst_indexed_node *node_b;

    node_a = data -> stack_a;
    node_b = data -> stack_b;
    if (data -> size_a == 2)
    {
        if (node_a -> value < (node_a + 1)->value) {
            /*
                Operaciones pb / pa /sa ....
            */
        }else{
            /*
                Operaciones pb / pa /sa ....
            */
        }
    }
    else if (data -> size_a == 3)
    {
        /*
            Operaciones pb / pa /sa ....
        */
    }
}
void push_swap(t_data *data)
{
    sort_small_list(data);
}
