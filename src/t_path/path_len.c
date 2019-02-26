/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Get the len of the path list.
*/

int		path_len(t_path *path)
{
	int len;

	len = 0;
	while (path)
	{
		path = path->next;
		len += 1;
	}
	return (len);
}
