/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>

# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <errno.h>
# include <dirent.h>

# include <stdlib.h>
# include <string.h>

/*
** Local header files
*/

# include "libft.h"
# include "t_file.h"
# include "t_path.h"

/*
** Error Flags
*/

# define	MEM_ERR		(3)
# define	DIR_ERR		(2)
# define	FLG_ERR		(1)

/*
** Valid option flags
*/

# define	OPT_FLGS	("aAcfglrRStTu1")

/*
** Seconds in 6 months
** "A timestamp is considered to be recent if 
** it is less than six months old..."
*/

# define	SIX_MONTHS	(15778800)

/*
** Main program
*/

void		ft_ls(t_path *path, char *opt);

/*
** Print funtions
*/

void		print_name(t_file *file);
void		print_type(t_file *file);
void		print_perm(t_file *file, char *path);
void		print_date(t_file *file, char *opt, int *count);
void		print_list(t_file *file, char *path, int type, char *opt);

/*
** Utils functions
*/

int			cmp_ts_n(int a, int b, char *s1, char *s2);
t_file		*create_file(char *path, char *opt, int type);
void		delete_files(t_file *files);

#endif
