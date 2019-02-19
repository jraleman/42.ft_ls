#include "ft_ls.h"

/*
** ...
*/

int     path_len(t_path *path)
{
    int len;

    len = 0;
    while (path)
    {
        path = path->next;
        len += 1;
    }
    return (len);
}