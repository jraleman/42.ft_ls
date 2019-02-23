#include "ft_ls.h"

t_path		*ls_psort_size(t_path *path, int rev)
{
	t_path		*begin;
	t_path		*tmp;
	struct stat tstat;
	struct stat pstat;

	tmp = NULL;
	begin = path;
	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			lstat(path->name, &pstat);
			lstat(tmp->name, &tstat);
			if ((ft_int_str_cmp(pstat.st_size, tstat.st_size, path->name,
						tmp->name) < 0 && !rev) ||
					(ft_int_str_cmp(pstat.st_size, tstat.st_size, path->name,
						tmp->name) > 0 && rev))
				path_swp(path, tmp);
			tmp = tmp->next;
		}
		path = path->next;
	}
	return (begin);
}