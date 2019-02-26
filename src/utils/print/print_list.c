/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
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

static int		ls_n_blocks(t_file *info)
{
	int			total;

	total = 0;
	while (info)
	{
		total += info->stat.st_blocks;
		info = info->next;
	}
	return (total);
}

/*
** ...
*/

static char		*ls_relink(t_file *info, char *path, int type)
{
	char		buf[1024];
	char		*tmp;
	ssize_t		len;

	if (type == 2)
		tmp = ft_strdup(path);
	else
		tmp = ft_zprintf("%s/%s", path, info->name);
	if ((len = readlink(tmp, buf, sizeof(buf) - 1)) != -1)
		buf[len] = '\0';
	ft_strdel(&tmp);
	return (ft_zprintf("%s -> %s", info->name, buf));
}

/*
** ...
*/

static void		ls_sprint_rest(t_file *info, char *path, char *opt, int type)
{
	int			i;

	i = 0;
	info->entry[i++] = ft_zprintf("%ld", info->stat.st_nlink);
	if (!ft_cisin(opt, 'g') && getpwuid(info->stat.st_uid))
		info->entry[i++] = ft_zprintf("%s",
			getpwuid(info->stat.st_uid)->pw_name);
	else if (!ft_cisin(opt, 'g'))
		info->entry[i++] = ft_zprintf("%d", info->stat.st_uid);
	info->entry[i++] = ft_zprintf(" %s", getgrgid(info->stat.st_gid)->gr_name);
	if (S_ISCHR(info->stat.st_mode) || S_ISBLK(info->stat.st_mode))
		info->entry[i++] = ft_zprintf("%u, %3u", major(info->stat.st_rdev),
			minor(info->stat.st_rdev));
	else
		info->entry[i++] = ft_zprintf(" %lld", info->stat.st_size);
	print_date(info, opt, &i);
	if (S_ISLNK(info->stat.st_mode))
		info->entry[i++] = ls_relink(info, path, type);
	else
		info->entry[i++] = ft_zprintf("%s", info->name);
	info->entry[i] = NULL;
}

/*
** ...
*/

static int		*file_inilen_l(t_file *info)
{
	t_file		*tmp;
	int			count;
	int			*len;

	count = 0;
	len = NULL;
	if (!(len = (int*)malloc(sizeof(int) * 9)))
		return (NULL);
	tmp = info;
	while (tmp->entry[count + 1])
	{
		len[count] = 0;
		while (tmp)
		{
			if ((int)ft_strlen(tmp->entry[count]) > len[count])
				len[count] = ft_strlen(tmp->entry[count]);
			tmp = tmp->next;
		}
		tmp = info;
		count++;
	}
	len[count] = 0;
	return (len);
}

/*
** ...
*/

void			print_list(t_file *info, char *path, int type, char *opt)
{
	t_file		*tmp;
	int			count;
	int			*len;

	count = 0;
	tmp = info;
	(type != 2) ? ft_printf("total %d\n", ls_n_blocks(info)) : 0;
	while (tmp)
	{
		ls_sprint_rest(tmp, path, opt, type);
		tmp = tmp->next;
	}
	if (!(len = file_inilen_l(info)))
		return ;
	while (info)
	{
		print_type(info);
		print_perm(info, path);
		count = -1;
		while (info->entry[++count + 1])
			ft_printf("%*s", len[count] + 1, info->entry[count]);
		ft_printf(" %s\n", info->entry[count]);
		info = info->next;
	}
	free(len);
}
