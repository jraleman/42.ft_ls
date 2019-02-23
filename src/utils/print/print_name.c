#include "ft_ls.h"

void	print_name(t_file *file)
{
	while (file)
	{
		ft_printf("%s\n", file->name);
		file = file->next;
	}
	return ;
}