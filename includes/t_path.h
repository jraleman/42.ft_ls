#ifndef T_PATH
# define T_PATH

// ...
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

typedef struct		s_path
{
	char			*name;
	int				error;
	struct s_path	*next;
}					t_path;

int					path_len(t_path *path);
void				path_del(t_path *path);
void				path_swp(t_path *a, t_path *b);
t_path				*path_srt(t_path *path, char *opt);
t_path				*path_add(t_path *path, char *dir, char *opt);

#endif