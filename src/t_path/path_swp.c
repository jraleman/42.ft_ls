#include "ft_ls.h"

/*
** ...
*/

void        path_swp(t_path *a, t_path *b)
{
    char    *name;
    int     type;

    name = a->name;
    type = a->type;
    a->name = b->name;
    a->type = b->type;
    b->name = name;
    b->type = type;
    return ;
}