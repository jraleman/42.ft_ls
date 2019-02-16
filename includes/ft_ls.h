/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:42:27 by jaleman           #+#    #+#             */
/*   Updated: 2018/10/23 16:42:27 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define  FT_LS_H

# include <stdio.h>

# include "libft.h"

# define    LS_FLAGS   "lRart"

struct typedef 

int     ft_ls(t_ls *ls, char *path);
t_opt   parse_flags(int n, char const *flags[], t_opt *options);

#endif
