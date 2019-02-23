#include "ft_ls.h"

void	file_swp(t_file *a, t_file *b)
{
	struct stat		tmps;
	char			*tmpn;
	int	tmpt;

	tmpn = a->name;
	tmpt = a->type;
	tmps = a->stat;
	a->name = b->name;
	a->type = b->type;
	a->stat = b->stat;
	b->name = tmpn;
	b->type = tmpt;
	b->stat = tmps;
	return ;
}
