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

/*
** Get the difference between the times.
*/

static time_t	get_diff(time_t t, char *opt, t_file *file)
{
	time_t		tmp;
	char		*tm;

	if (ft_cisin(opt, 'u'))
	{
		tm = ctime(&file->stat.st_atime);
		tmp = file->stat.st_atime;
	}
	else if (ft_cisin(opt, 'c'))
	{
		tm = ctime(&file->stat.st_ctime);
		tmp = file->stat.st_ctime;
	}
	else
	{
		tm = ctime(&file->stat.st_mtime);
		tmp = file->stat.st_mtime;
	}
	return (t - tmp);
}

/*
** Prints the date of a file entry.
*/

void			print_date(t_file *file, char *opt, int *count)
{
	time_t		tme;
	char		*tm;

	tme = time(NULL);
	if (ft_cisin(opt, 'u'))
		tm = ctime(&file->stat.st_atime);
	else if (ft_cisin(opt, 'c'))
		tm = ctime(&file->stat.st_ctime);
	else
		tm = ctime(&file->stat.st_mtime);
	tm[ft_strlen(tm) - 1] = '\0';
	if (get_diff(tme, opt, file) > SIX_MONTHS || get_diff(tme, opt, file) > tme)
	{
		if (!ft_cisin(opt, 'T'))
			file->entry[(*count)++] = ft_zprintf("%.6s  %.4s", tm + 4, tm + 20);
		else
			file->entry[(*count)++] = ft_zprintf("%s", tm + 4);
	}
	else
	{
		if (!ft_cisin(opt, 'T'))
			file->entry[(*count)++] = ft_zprintf("%.12s", tm + 4);
		else
			file->entry[(*count)++] = ft_zprintf("%s", tm + 4);
	}
}
