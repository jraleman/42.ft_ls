/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_srt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		get_timestap(struct stat path, char type)
{
	int			timestap;

	timestap = -1;
	{
		if (type == 'a')
			timestap = path.st_atime;
		else if (type == 'c')
			timestap = path.st_ctime;
		else if (type == 'm')
			timestap = path.st_mtime;
	}
	return (timestap);
}

static t_path	*sort_time(t_path *path, int reverse, char type)
{
	t_path		*begin;
	t_path		*tmp;
	struct stat	tstat;
	struct stat	pstat;
	int			timestap[2];

	tmp = NULL;
	begin = path;
	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			timestap[0] = get_timestap(pstat, type);
			timestap[1] = get_timestap(tstat, type);
			lstat(path->name, &pstat);
			lstat(tmp->name, &tstat);
			if ((cmp_ts_n(timestap[0], timestap[1], path->name,
						tmp->name) < 0 && !reverse) ||
					(cmp_ts_n(timestap[0], timestap[1], path->name,
						tmp->name) > 0 && reverse))
				path_swp(path, tmp);
			tmp = tmp->next;
		}
		path = path->next;
	}
	return (begin);
}

static t_path	*sort_size(t_path *path, int rev)
{
	t_path		*begin;
	t_path		*tmp;
	struct stat tstat;
	struct stat pstat;

	tmp = NULL;
	begin = path;
	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			lstat(path->name, &pstat);
			lstat(tmp->name, &tstat);
			if ((cmp_ts_n(pstat.st_size, tstat.st_size, path->name,
						tmp->name) < 0 && !rev) ||
					(cmp_ts_n(pstat.st_size, tstat.st_size, path->name,
						tmp->name) > 0 && rev))
				path_swp(path, tmp);
			tmp = tmp->next;
		}
		path = path->next;
	}
	return (begin);
}

static t_path	*sort_name(t_path *path, int rev)
{
	t_path		*begin;
	t_path		*tmp;

	tmp = NULL;
	begin = path;
	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			if ((ft_strcmp(path->name, tmp->name) > 0 && !rev) ||
				(ft_strcmp(path->name, tmp->name) < 0 && rev))
				path_swp(path, tmp);
			tmp = tmp->next;
		}
		path = path->next;
	}
	return (begin);
}


t_path			*path_srt(t_path *path, char *opt)
{
	t_path		*sort;
	int			reverse;

	reverse = ft_cisin(opt, 'r');
	if (ft_cisin(opt, 'S'))
		sort = sort_size(path, reverse);
	else if (ft_cisin(opt, 't'))
	{
		if (ft_cisin(opt, 'c'))
			sort = sort_time(path, reverse, 'c');
		else if (ft_cisin(opt, 'u'))
			sort = sort_time(path, reverse, 'a');
		else
			sort = sort_time(path, reverse, 'm');
	}
	else if (ft_cisin(opt, 'f'))
		sort = path;
	else
		sort = sort_name(path, reverse);
	return (sort);
}
