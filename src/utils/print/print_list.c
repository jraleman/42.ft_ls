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
** Get number of blocks in a file.
*/

static int		n_blocks(t_file *file)
{
	int			total;

	total = 0;
	while (file)
	{
		total += file->stat.st_blocks;
		file = file->next;
	}
	return (total);
}

/*
** Prints files in a list.
*/

void			print_list(t_file *file, char *path, char *opt, int type)
{
	t_file		*tmp;
	int			i;
	int			*len;

	i = 0;
	tmp = file;
	(type != SYM_PATH) ? ft_printf("total %d\n", n_blocks(file)) : 0;
	while (tmp)
	{
		print_entry(tmp, path, opt, type);
		tmp = tmp->next;
	}
	if (!(len = file_len(file)))
		return ;
	while (file)
	{
		print_type(file);
		print_perm(file, path);
		i = -1;
		while (file->entry[++i + 1])
			ft_printf("%*s", len[i] + 1, file->entry[i]);
		ft_printf(" %s\n", file->entry[i]);
		file = file->next;
	}
	free(len);
}
