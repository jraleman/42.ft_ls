#include "ft_ls.h"

static t_file	*ls_frouter(char *path, char *opt, int type)
{
	return (type == 1 ? file_dir(path, opt) : file_ini(path));
}

static void		ls_router(char *opt, t_file *info, char *path, int type)
{
	if (info)
		ft_cisin(opt, 'g') || ft_cisin(opt, 'l') \
			? print_list(info, path, type, opt) : print_name(info);
	return ;
}

static void		file_inisdel(t_file *info)
{
	while (info)
		info = file_del(info);
	return ;
}

static void		ls_ls(char *path, int type, char *opt, int count)
{
	t_file		*info;

	if (count && type != 2)
		ft_printf("%s:\n", path);
	info = ls_frouter(path, opt, type);
	
	info = file_srt(info, opt);

	ls_router(opt, info, path, type);
	while (info && ft_cisin(opt, 'R'))
	{
		if (info->type == 4 && ft_strcmp(".", info->name) &&
				ft_strcmp("..", info->name))
		{
			ft_printf("\n");
			if (!ft_strcmp("/", path))
				ls_ls(ft_zprintf("%s%s", path, info->name), 1, opt, count + 1);
			else
				ls_ls(ft_zprintf("%s/%s", path, info->name), 1, opt, count + 1);
		}
		info = file_del(info);
	}
	file_inisdel(info);
	ft_strdel(&path);
	return ;
}


void			ls_main(t_path *path, char *opt)
{
	int			count;
	int			i;
	t_path		*tmp;

	count = 0;
	i = 0;
	tmp = path;
	while (tmp)
	{
		(tmp->error == 2) ? ls_ls(tmp->name, tmp->error, opt, count++) : 0;
		(tmp->error == 2) ? i++ : 0;
		tmp = tmp->next;
	}
	count = path_len(path) - 1;
	tmp = path;
	while (tmp)
	{
		if (tmp->error == 1)
		{
			(i) ? ft_printf("\n") : 0;
			i = 1;
			ls_ls(tmp->name, tmp->error, opt, count++);
		}
		tmp = tmp->next;
	}
	return ;
}