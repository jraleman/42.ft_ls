/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_path.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PATH
# define T_PATH

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
** Path types
*/

# define	DIR_PATH	(1)
# define	SYM_PATH	(2)

typedef struct		s_path
{
	char			*name;
	int				type;
	struct s_path	*next;
}					t_path;

int					path_len(t_path *path);
void				path_del(t_path *path);
void				path_swp(t_path *a, t_path *b);
t_path				*path_srt(t_path *path, char *opt);
t_path				*path_add(t_path *path, char *dir, char *opt);

#endif
