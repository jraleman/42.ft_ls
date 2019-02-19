#include "ft_ls.h"

/*
** ...
*/

t_path  *path_add(t_path *path, char *dir, char *opt)
{
    t_path  *tmp;
    t_path  *last;

    if (!(last = malloc(sizeof(t_path))))
        return (NULL);
    last->next = NULL;
    if (!path)
        return (last);
    tmp = path;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = last;
    return (path);
}