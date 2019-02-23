#include "ft_ls.h"

/*
** ...
*/ 

t_file		*file_ini(char *path)
{
	struct stat	vstat;
	t_file		*file;

	file = NULL;
	lstat(path, &vstat);
	file = file_add(file, path, vstat, 0);
	return (file);
}
