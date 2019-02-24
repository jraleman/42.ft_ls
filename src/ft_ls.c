#include "ft_ls.h"

// create_file
static t_file	*create_file(char *path, char *opt, int type)
{
	return (type == 1 ? file_dir(path, opt) : file_ini(path));
}
// select_print
static void		select_print(char *opt, t_file *file, char *path, int type)
{
	if (file)
		ft_cisin(opt, 'g') || ft_cisin(opt, 'l') \
			? print_list(file, path, type, opt) : print_name(file);
	return ;
}

static void		delete_files(t_file *files)
{
	while (files)
		files = file_del(files);
	return ;
}

/*
** Return : N/A
** Master function.
** 
*/

static void		ls(char *path, int type, char *opt, int count)
{
	t_file		*info;

	if (count && type != 2)
		ft_printf("%s:\n", path);
	info = create_file(path, opt, type);
	info = file_srt(info, opt);
	select_print(opt, info, path, type);
	while (info && ft_cisin(opt, 'R'))
	{
		if (info->type == 4 && ft_strcmp(".", info->name) &&
				ft_strcmp("..", info->name))
		{
			ft_printf("\n");
			if (!ft_strcmp("/", path))
				ls(ft_zprintf("%s%s", path, info->name), 1, opt, count + 1);
			else
				ls(ft_zprintf("%s/%s", path, info->name), 1, opt, count + 1);
		}
		info = file_del(info);
	}
	delete_files(info);
	ft_strdel(&path);
	return ;
}



void			ft_ls(t_path *path, char *opt)
{
	int			count;
	int			i;
	t_path		*tmp;


	// funct 1
	count = 0;
	i = 0;
	tmp = path;
	while (tmp)
	{
		(tmp->error == 2) ? ls(tmp->name, tmp->error, opt, count++) : 0;
		(tmp->error == 2) ? i++ : 0;
		tmp = tmp->next;
	}

	// funct 2
	count = path_len(path) - 1;
	tmp = path;
	while (tmp)
	{
		if (tmp->error == 1)
		{
			(i) ? ft_printf("\n") : 0;
			i = 1;
			ls(tmp->name, tmp->error, opt, count++);
		}
		tmp = tmp->next;
	}



	return ;
}