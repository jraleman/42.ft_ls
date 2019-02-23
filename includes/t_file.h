#ifndef T_FILE
# define T_FILE

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

# define 			NUM_ENTRIES		(9)

typedef struct		s_file
{
	char			*name;
	int				type;
	struct stat		stat;
	char			*entry[NUM_ENTRIES];
	struct s_file	*next;
	struct s_file	*prev;
}					t_file;

void				file_swp(t_file *a, t_file *b);
t_file				*file_ini(char *path);
t_file				*file_del(t_file *info);
t_file				*file_dir(char *path, char *opt);
t_file				*file_srt(t_file *info, char *opt);
t_file				*file_add(t_file *info, char *name, struct stat vstat, int type);

#endif