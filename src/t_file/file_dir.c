/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** ...
*/ 

static t_file		*file_dir_create(DIR *ptr, char *path, char *opt)
{
	t_file			*dir;
	struct dirent	*ret;
	char			*cpath;
	struct stat		vstat;

	dir = NULL;
	while ((ret = readdir(ptr)))
	{
		if (ret->d_name[0] == '.' \
				&& !ft_cisin(opt, 'a') && !ft_cisin(opt, 'A') && !ft_cisin(opt, 'f'))
			continue;
		if ((!ft_strcmp(".", ret->d_name) || !ft_strcmp("..", ret->d_name)) \
				&& ft_cisin(opt, 'A'))
			continue;
		cpath = ft_zprintf("%s/%s", path, ret->d_name);
		lstat(cpath, &vstat);
		dir = file_add(dir, ret->d_name, vstat, ret->d_type);
		ft_strdel(&cpath);
	}
	if (ret)
		free(ret);
	return (dir);
}

/*
** ...
*/ 

t_file		*file_dir(char *path, char *opt)
{
	t_file			*dir;
	DIR				*ptr;

	dir = NULL;
	ptr = opendir(path);
	if (ptr)
	{
		dir = file_dir_create(ptr, path, opt);
		closedir(ptr);
	}
	else
		ft_dprintf(2, "ls: %s: %s\n", path, strerror(errno));
	return (dir);
}

