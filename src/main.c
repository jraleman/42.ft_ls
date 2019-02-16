/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:42:16 by jaleman           #+#    #+#             */
/*   Updated: 2018/10/23 16:42:17 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int   main(int argc, char const *argv[])
{
    t_ls    *ls;
    char    *path;

    if (read_flags(ls, argc, argv) > 1)
        ft_ls(ls, path);
    else
        ft_ls(ls, ".");
    return (0);
}
