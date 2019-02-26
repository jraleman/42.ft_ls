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
** Prints the user rights of a file entry.
*/

void	print_perm(t_file *file, char *path)
{
	char			buf[1024];
	char			*t;
	ssize_t			l;

	ft_putchar((file->stat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((file->stat.st_mode & S_IWUSR) ? 'w' : '-');
	if (file->stat.st_mode & S_ISUID)
		ft_putchar((file->stat.st_mode & S_IXUSR) ? 's' : 'S');
	else
		ft_putchar((file->stat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((file->stat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((file->stat.st_mode & S_IWGRP) ? 'w' : '-');
	if (file->stat.st_mode & S_ISGID)
		ft_putchar((file->stat.st_mode & S_IXGRP) ? 's' : 'S');
	else
		ft_putchar((file->stat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((file->stat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((file->stat.st_mode & S_IWOTH) ? 'w' : '-');
	if (file->stat.st_mode & S_ISVTX)
		ft_putchar((file->stat.st_mode & S_IXOTH) ? 't' : 'T');
	else
		ft_putchar((file->stat.st_mode & S_IXOTH) ? 'x' : '-');
	t = ft_zprintf("%s/%s", path, file->name);
	ft_putchar(((l = listxattr(t, buf, sizeof(buf) - 1, 0)) > 0) ? '@' : ' ');
	ft_strdel(&t);
}
