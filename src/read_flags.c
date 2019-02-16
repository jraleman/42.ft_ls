/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 00:43:16 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/16 00:43:18 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void set_flag(t_opt *opt, char *flag)
{
    // ...
    return ;
}

static int  check_flag()
{
    // ...
    return (0);
}

static int  verify_flag(char *flag)
{
    return (ft_strlen(flag) && flags[0] == '-' \
            && ft_strchr(LS_FLAGS, flag[1]));
}

int         read_flags(t_ls *ls, int n, char const *flags[])
{
    int     i;

    i = 0;
    while (++i < n)
        if (verify_flag(flags[i]))
            set_flag(ls->opt, flags[i]);
    return (i);
}
