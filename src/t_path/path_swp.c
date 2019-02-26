/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_swp.c                                         :+:      :+:    :+:   */
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

void        path_swp(t_path *a, t_path *b)
{
    char    *name;
    int     type;

    name = a->name;
    type = a->type;
    a->name = b->name;
    a->type = b->type;
    b->name = name;
    b->type = type;
    return ;
}