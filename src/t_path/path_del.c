#include "ft_ls.h"

/*
** ...
*/

void    path_del(t_path *path)
{
    t_path  *tmp;

    while (path)
    {
        if (path->type == DIR_ERR)
            ft_strdel(&(path->name));
        tmp = path;
        path = path->next;
        free(tmp);
    }
    return ;
}