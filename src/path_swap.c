#include "ft_ls.h"

/*
** ...
*/

void        path_swap(t_path *a, t_path *b)
{
    char    *name;
    int     error;

    name = a->name;
    error = a->error;
    a->name = b->name;
    a->error = b->error;
    b->name = name;
    b->error = error;
    return ;
}