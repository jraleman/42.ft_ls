#include "ft_ls.h"

t_path		*path_srt(t_path *path, char *opt)
{
	if (ft_cisin(opt, 'S'))
		return (ls_psort_size(path, ft_cisin(opt, 'r')));
	else if (ft_cisin(opt, 't'))
	{
		if (ft_cisin(opt, 'c'))
			return (ls_psort_ctime(path, ft_cisin(opt, 'r')));
		else if (ft_cisin(opt, 'u'))
			return (ls_psort_atime(path, ft_cisin(opt, 'r')));
		return (ls_psort_mtime(path, ft_cisin(opt, 'r')));
	}
	else if (ft_cisin(opt, 'f'))
		return (path);
	else
		return (ls_psort_name(path, ft_cisin(opt, 'r')));
}
