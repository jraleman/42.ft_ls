
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

/*
** Return : N/A
** Master function.
** 
*/

// static int		list_symlinks();
	// int			count;
	// int			i;
	// t_path		*tmp;

	// // list_symlinks
	// count = 0;
	// i = 0;
	// tmp = path;
	// while (tmp)
	// {
	// 	if (tmp->type == 2)
	// 	{
	// 		ls(tmp->name, tmp->type, opt, count);
	// 		count += 1;
	// 		i += 1;
	// 	}
	// 	tmp = tmp->next;
	// }


// static int		list_dirs();
	// count = path_len(path) - 1;
	// tmp = path;
	// while (tmp)
	// {
	// 	if (tmp->type == 1)
	// 	{
	// 		if (i)
	// 			ft_printf("\n");
	// 		ls(tmp->name, tmp->type, opt, count);
	// 		count += 1;
	// 		i = 1;
	// 	}
	// 	tmp = tmp->next;
	// }


void			ft_ls(t_path *path, char *opt)
{
	int			count;
	int			i;
	t_path		*tmp;

	// int			sym_flg;

	// sym_flg = list_symlinks();

	// list_symlinks
	count = 0;
	i = 0;
	tmp = path;
	while (tmp)
	{
		if (tmp->type == 2)
		{
			ls(tmp->name, tmp->type, opt, count);
			count += 1;
			i += 1;
		}
		tmp = tmp->next;
	}

	// list_dirs
	count = path_len(path) - 1;
	tmp = path;
	while (tmp)
	{
		if (tmp->type == 1)
		{
			if (i)
				ft_printf("\n");
			ls(tmp->name, tmp->type, opt, count);
			count += 1;
			i = 1;
		}
		tmp = tmp->next;
	}


	return ;
}