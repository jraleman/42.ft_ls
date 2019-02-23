#include "ft_ls.h"

t_file		*file_srt(t_file *file, char *opt)
{
	// t_file	*sort;

	// sort = ls_sort_name(file, ft_cisin(opt, 'r'));
	// if (ft_cisin(opt, 'S'))
	// 	sort = ls_sort_size(file, ft_cisin(opt, 'r'));
	// else if (ft_cisin(opt, 't'))
	// {
	// 	if (ft_cisin(opt, 'c'))
	// 		sort = ls_sort_ctime(file, ft_cisin(opt, 'r'));
	// 	else if (ft_cisin(opt, 'u'))
	// 		sort = ls_sort_atime(file, ft_cisin(opt, 'r'));
	// 	else
	// 		sort = ls_sort_mtime(file, ft_cisin(opt, 'r'));
	// }
	// else if (ft_cisin(opt, 'f'))
	// 	sort = file;
	// return (sort);
	if (ft_cisin(opt, 'S'))
		return (ls_sort_size(file, ft_cisin(opt, 'r')));
	else if (ft_cisin(opt, 't'))
	{
		if (ft_cisin(opt, 'c'))
			return (ls_sort_ctime(file, ft_cisin(opt, 'r')));
		else if (ft_cisin(opt, 'u'))
			return (ls_sort_atime(file, ft_cisin(opt, 'r')));
		return (ls_sort_mtime(file, ft_cisin(opt, 'r')));
	}
	else if (ft_cisin(opt, 'f'))
		return (file);
	else
		return (ls_sort_name(file, ft_cisin(opt, 'r')));
}
