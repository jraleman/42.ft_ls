/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Delete a file from
*/

t_file		*file_del(t_file *file)
{
	int		i;
	t_file	*tmp;

	i = -1;
	tmp = (!file ? NULL : file->next);
	if (file || file->next)
	{
		ft_strdel(&(file->name));
		while (file->entry[++i])
			ft_strdel(&(file->entry[i]));
		free(file);
		file = NULL;
	}
	return (tmp);
}
