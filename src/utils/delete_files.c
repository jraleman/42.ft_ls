#include "ft_ls.h"

/*
** ...
*/

void		delete_files(t_file *files)
{
	while (files)
		files = file_del(files);
	return ;
}