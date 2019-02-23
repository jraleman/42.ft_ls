#include "ft_ls.h"

static void		parse_flag(char *bin, char *s, char *opt)
{
	int 		i;

	i = 1;
	while (s[i])
	{
		if (!ft_cisin("aAcfglrRStTu1", s[i]))
		{
			ft_printf("%s: illegal option -- %c\n", bin, s[i]);
			ft_printf("usage: %s [-ARSTacfglrtu1] [file ...]", bin);
			exit(1);
		}
		else if (!ft_cisin(opt, s[i]))
			ft_strncat(opt, &(s[i]), 1);
		i += 1;
	}
	return ;
}

static t_path	*opt_flags(char *opt, char *flags[], int total)
{
	int			i;
	t_path		*path;

	i = 0;
	path = NULL;
	while (++i < total)
	{
		if (!ft_strcmp(flags[i], "--"))
			i += 1;
		else if (flags[i][0] == '-')
		{
			parse_flag(flags[0], flags[i], opt);
			continue ;
		}
		break ;
	}
	while (++i <= total)
		path = path_add(path, flags[i - 1], opt);
	return (path);
}

/*
** Return values
** -> 0 : success
** -> 1 : illegal flag
** -> 2 : memory allocation error
*/

int				main(int argc, char *argv[])
{
	t_path		*path;
	char		*opt;

	opt = ft_strnew(13);
	if (opt)
	{
		path = opt_flags(opt, argv, argc);
		if (!path)
			path = path_add(path, ".", opt);
		path = path_srt(path, opt);
		ls_main(path, opt);
		path_del(path);
		ft_strdel(&opt);
	}
	return (!opt ? 2 : 0);
}
