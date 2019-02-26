/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**  Add a new file to store data at the end of the file list.
*/

t_file	*file_add(t_file *file, char *name, struct stat vstat, int type)
{
	t_file *last;
	t_file *tmp;

	last = (t_file *)malloc(sizeof(t_file));
	if (last)
	{
		last->name = ft_strdup(name);
		last->type = type;
		last->entry[0] = NULL;
		last->stat = vstat;
		last->next = NULL;
		if (file)
		{
			tmp = file;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = last;
		}
	}
	return (last && (!file || !last) ? last : file);
}
