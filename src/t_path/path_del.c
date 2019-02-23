#include "ft_ls.h"

/*
** ...
*/

void    path_del(t_path *path)
{
    t_path  *tmp;

    while (path)
    {
        if (path->error == -1)
            ft_strdel(&(path->name));
        tmp = path;
        path = path->next;
        free(tmp);
    }
    return ;
}