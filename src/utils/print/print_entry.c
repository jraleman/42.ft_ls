/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_perm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Relink a file entry.
*/

static char		*relink_entry(t_file *file, char *path, int type)
{
	char		buf[1024];
	char		*tmp;
	ssize_t		len;

	if (type == SYM_PATH)
		tmp = ft_strdup(path);
	else
		tmp = ft_zprintf("%s/%s", path, file->name);
	if ((len = readlink(tmp, buf, sizeof(buf) - 1)) != -1)
		buf[len] = '\0';
	ft_strdel(&tmp);
	return (ft_zprintf("%s -> %s", file->name, buf));
}

/*
** Prints a file entry.
*/

void			print_entry(t_file *file, char *path, char *opt, int type)
{
	int			i;

	i = 0;
	file->entry[i++] = ft_zprintf("%ld", file->stat.st_nlink);
	if (!ft_cisin(opt, 'g') && getpwuid(file->stat.st_uid))
		file->entry[i++] = ft_zprintf("%s",
			getpwuid(file->stat.st_uid)->pw_name);
	else if (!ft_cisin(opt, 'g'))
		file->entry[i++] = ft_zprintf("%d", file->stat.st_uid);
	file->entry[i++] = ft_zprintf(" %s", getgrgid(file->stat.st_gid)->gr_name);
	if (S_ISCHR(file->stat.st_mode) || S_ISBLK(file->stat.st_mode))
		file->entry[i++] = ft_zprintf("%u, %3u", major(file->stat.st_rdev),
			minor(file->stat.st_rdev));
	else
		file->entry[i++] = ft_zprintf(" %lld", file->stat.st_size);
	print_date(file, opt, &i);
	if (S_ISLNK(file->stat.st_mode))
		file->entry[i++] = relink_entry(file, path, type);
	else
		file->entry[i++] = ft_zprintf("%s", file->name);
	file->entry[i] = NULL;
	return ;
}