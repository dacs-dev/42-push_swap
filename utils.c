#include "push_swap.h"

int str_isnum(char *str)
{
    if (!str || !*str)
        return (0);
    if (*str == '-' || *str == '+')
        str++;
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (0);
        str++;
    }
    return (1);
}

void	ft_free_split(char **arr)
{
	char	**tmp;

	if (arr != NULL)
    {
        tmp = arr;
        while (*tmp)
        {
            free(*tmp);
            tmp++;
        }
        free(arr);
    }
}

int is_sorted(t_lst_indexed_node *stack)
{

	while (stack->next)
	{
		if (stack->index != stack->next->index - 1)
			return 0;
		stack = stack->next;
	}
	return 1;
}