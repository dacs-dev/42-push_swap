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
