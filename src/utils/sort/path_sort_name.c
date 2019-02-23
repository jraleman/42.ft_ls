#include "ft_ls.h"

t_path		*ls_psort_name(t_path *path, int rev)
{
	t_path	*begin;
	t_path	*tmp;

	tmp = NULL;
	begin = path;
	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			if ((ft_strcmp(path->name, tmp->name) > 0 && !rev) ||
				(ft_strcmp(path->name, tmp->name) < 0 && rev))
				path_swp(path, tmp);
			tmp = tmp->next;
		}
		path = path->next;
	}
	return (begin);
}