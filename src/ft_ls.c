
#include "ft_ls.h"

/*
** Print as list if the opt flag is `g` or `l`.
** Else, print by name.
*/

static void		select_print(char *opt, t_file *file, char *path, int type)
{
	if (file)
		ft_cisin(opt, 'g') || ft_cisin(opt, 'l') \
			? print_list(file, path, type, opt) : print_name(file);
	return ;
}

static void		ls(char *path, int type, char *opt, int count)
{
	t_file		*file;

	if (count && type != 2)
		ft_printf("%s:\n", path);
	file = create_file(path, opt, type);
	select_print(opt, file, path, type);
	while (file && ft_cisin(opt, 'R'))
	{
		if (ft_strcmp(".", file->name) && ft_strcmp("..", file->name) \
			&& file->type == 4)
		{
			ft_printf("\n");
			if (!ft_strcmp("/", path))
				ls(ft_zprintf("%s%s", path, file->name), 1, opt, count + 1);
			else
				ls(ft_zprintf("%s/%s", path, file->name), 1, opt, count + 1);
		}
		file = file_del(file);
	}
	delete_files(file);
	ft_strdel(&path);
	return ;
}

static int		list_symlnk(t_path *path, char *opt)
{
	int			i;
	int			sym_lnk;
	t_path		*tmp;

	i = 0;
	sym_lnk = 0;
	tmp = path;
	while (tmp)
	{
		if (tmp->type == SYM_PATH)
		{
			ls(tmp->name, tmp->type, opt, i);
			i += 1;
			sym_lnk += 1;
		}
		tmp = tmp->next;
	}
	return (sym_lnk);
}

void			ft_ls(t_path *path, char *opt)
{
	int			sym_lnk;
	int 		len;
	t_path		*tmp;

	sym_lnk = list_symlnk(path, opt);
	len = path_len(path) - 1;
	tmp = path;
	while (tmp)
	{
		if (tmp->type == 1)
		{
			if (sym_lnk > 0)
				ft_printf("\n");
			ls(tmp->name, tmp->type, opt, len);
			len += 1;
			sym_lnk = 1;
		}
		tmp = tmp->next;
	}
	return ;
}