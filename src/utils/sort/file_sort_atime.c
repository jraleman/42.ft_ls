#include "ft_ls.h"

t_file		*ls_sort_atime(t_file *info, int rev)
{
	t_file	*begin;
	t_file	*tmp;

	tmp = NULL;
	begin = info;
	while (info)
	{
		tmp = info->next;
		while (tmp)
		{
			if ((ft_int_str_cmp(info->stat.st_atime, tmp->stat.st_atime,
						info->name, tmp->name) < 0 && !rev) ||
					(ft_int_str_cmp(info->stat.st_atime, tmp->stat.st_atime,
						info->name, tmp->name) > 0 && rev))
				file_swp(info, tmp);
			tmp = tmp->next;
		}
		info = info->next;
	}
	return (begin);
}