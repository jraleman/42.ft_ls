/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Get the len of the file entries.
*/

int				*file_len(t_file *file)
{
	t_file		*tmp;
	int			count;
	int			*len;

	count = 0;
	len = NULL;
	if (!(len = (int*)malloc(sizeof(int) * NUM_ENTRIES)))
		return (NULL);
	tmp = file;
	while (tmp->entry[count + 1])
	{
		len[count] = 0;
		while (tmp)
		{
			if ((int)ft_strlen(tmp->entry[count]) > len[count])
				len[count] = ft_strlen(tmp->entry[count]);
			tmp = tmp->next;
		}
		tmp = file;
		count++;
	}
	len[count] = 0;
	return (len);
}
