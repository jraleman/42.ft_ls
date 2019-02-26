/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_del.c                                         :+:      :+:    :+:   */
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

void    path_del(t_path *path)
{
    t_path  *tmp;

    while (path)
    {
        if (path->type == DIR_ERR)
            ft_strdel(&(path->name));
        tmp = path;
        path = path->next;
        free(tmp);
    }
    return ;
}