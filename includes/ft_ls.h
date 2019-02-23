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

# include "libft.h"
# include "t_file.h"
# include "t_path.h"

/*
** Seconds in 6 months
** "A timestamp is considered to be recent if it is less than six months old..."
** src: http://www.gnu.org/software/coreutils/manual/coreutils.html#Formatting-file-timestamps
*/
# define    SIX_MONTHS     15778800

/* path: ft_ls.c */
void	    ls_main(t_path *path, char *opt);
/* path: utils/print/{.c} */
void	    print_perm(t_file *info, char *path);
void	    print_date(t_file *info, char *opt, int *count);
void	    print_type(t_file *info);
void	    print_list(t_file *info, char *path, int type, char *opt);
void	    print_name(t_file *info);
// sort
t_file		*ls_sort_size(t_file *info, int rev);
t_file		*ls_sort_name(t_file *info, int rev);
t_file		*ls_sort_mtime(t_file *info, int rev);
t_file		*ls_sort_ctime(t_file *info, int rev);
t_file		*ls_sort_atime(t_file *info, int rev);
t_path		*ls_psort_size(t_path *path, int rev);
t_path		*ls_psort_name(t_path *path, int rev);
t_path		*ls_psort_mtime(t_path *path, int rev);
t_path		*ls_psort_ctime(t_path *path, int rev);
t_path		*ls_psort_atime(t_path *path, int rev);

int			ft_int_str_cmp(int a, int b, char *s1, char *s2);

#endif
