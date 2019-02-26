/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_srt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		get_timestap(t_file *file, char type)
{
	int			timestap;

	timestap = -1;
	if (file)
	{
		if (type == 'a')
			timestap = file->stat.st_atime;
		else if (type == 'c')
			timestap = file->stat.st_ctime;
		else if (type == 'm')
			timestap = file->stat.st_mtime;
	}
	return (timestap);
}

static t_file	*sort_time(t_file *file, int reverse, char type)
{
	t_file		*begin;
	t_file		*tmp;
	int			timestap[2];

	tmp = NULL;
	begin = file;
	while (file)
	{
		tmp = file->next;
		timestap[0] = get_timestap(file, type);
		timestap[1] = get_timestap(tmp, type);
		while (tmp)
		{
			if ((cmp_ts_n(timestap[0], timestap[1], \
					file->name, tmp->name) < 0 && !reverse) \
				|| (cmp_ts_n(timestap[0], timestap[1],
					file->name, tmp->name) > 0 && reverse))
				file_swp(file, tmp);
			tmp = tmp->next;
		}
		file = file->next;
	}
	return (begin);
}

static t_file	*sort_size(t_file *file, int rev)
{
	t_file		*begin;
	t_file		*tmp;

	tmp = NULL;
	begin = file;
	while (file)
	{
		tmp = file->next;
		while (tmp)
		{
			if ((cmp_ts_n(file->stat.st_size, tmp->stat.st_size,
						file->name, tmp->name) < 0 && !rev) ||
					(cmp_ts_n(file->stat.st_size, tmp->stat.st_size,
						file->name, tmp->name) > 0 && rev))
				file_swp(file, tmp);
			tmp = tmp->next;
		}
		file = file->next;
	}
	return (begin);
}

static t_file	*sort_name(t_file *file, int rev)
{
	t_file		*begin;
	t_file		*tmp;

	tmp = NULL;
	begin = file;
	while (file)
	{
		tmp = file->next;
		while (tmp)
		{
			if ((ft_strcmp(file->name, tmp->name) > 0 && !rev) ||
				(ft_strcmp(file->name, tmp->name) < 0 && rev))
				file_swp(file, tmp);
			tmp = tmp->next;
		}
		file = file->next;
	}
	return (begin);
}

t_file			*file_srt(t_file *file, char *opt)
{
	t_file		*sort;
	int			reverse;

	reverse = ft_cisin(opt, 'r');
	if (ft_cisin(opt, 'S'))
		sort = sort_size(file, reverse);
	else if (ft_cisin(opt, 't'))
	{
		if (ft_cisin(opt, 'c'))
			sort = sort_time(file, reverse, 'c');
		else if (ft_cisin(opt, 'u'))
			sort = sort_time(file, reverse, 'a');
		else
			sort = sort_time(file, reverse, 'm');
	}
	else if (ft_cisin(opt, 'f'))
		sort = file;
	else
		sort = sort_name(file, reverse);
	return (sort);
}
