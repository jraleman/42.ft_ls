/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_date.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static time_t	get_diff(time_t t, char *opt, t_file *info)
{
	time_t	tmp;
	char	*tm;

	if (ft_cisin(opt, 'u'))
	{
		tm = ctime(&info->stat.st_atime);
		tmp = info->stat.st_atime;
	}
	else if (ft_cisin(opt, 'c'))
	{
		tm = ctime(&info->stat.st_ctime);
		tmp = info->stat.st_ctime;
	}
	else
	{
		tm = ctime(&info->stat.st_mtime);
		tmp = info->stat.st_mtime;
	}
	return (t - tmp);
}

void	print_date(t_file *info, char *opt, int *count)
{
	time_t			tme;
	char			*tm;

	tme = time(NULL);
	if (ft_cisin(opt, 'u'))
		tm = ctime(&info->stat.st_atime);
	else if (ft_cisin(opt, 'c'))
		tm = ctime(&info->stat.st_ctime);
	else
		tm = ctime(&info->stat.st_mtime);
	tm[ft_strlen(tm) - 1] = '\0';
	if (get_diff(tme, opt, info) > SIX_MONTHS || get_diff(tme, opt, info) > tme)
	{
		if (!ft_cisin(opt, 'T'))
			info->entry[(*count)++] = ft_zprintf("%.6s  %.4s", tm + 4, tm + 20);
		else
			info->entry[(*count)++] = ft_zprintf("%s", tm + 4);
	}
	else
	{
		if (!ft_cisin(opt, 'T'))
			info->entry[(*count)++] = ft_zprintf("%.12s", tm + 4);
		else
			info->entry[(*count)++] = ft_zprintf("%s", tm + 4);
	}
}