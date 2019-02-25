#include "ft_ls.h"

/*
** Validate a flag.
** Print usage message and exit program if a flag is not valid.
** Returns : N/A | EXIT(FLG_ERR)
*/

static void		validate_flag(char *bin, char *s, char *opt)
{
	int 		i;

	i = 1;
	while (s[i])
	{
		if (!ft_cisin(OPT_FLGS, s[i]))
		{
			ft_printf("%s: illegal option -- %c\n", bin, s[i]);
			ft_printf("usage: %s [%s] [file ...]\n", bin, OPT_FLGS);
			return (exit(FLG_ERR));
		}
		else if (!ft_cisin(opt, s[i]))
			ft_strncat(opt, &(s[i]), 1);
		i += 1;
	}
	return ;
}

/*
** Parse the option flags.
** Returns : A path structure with valid option flags.
*/ 

static t_path	*parse_opt(char *opt, char *flags[], int total)
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
			validate_flag(flags[0], flags[i], opt);
			continue ;
		}
		break ;
	}
	while (++i <= total)
		path = path_add(path, flags[i - 1], opt);
	return (path);
}

/*
** Main program function.
*/

int				main(int argc, char *argv[])
{
	t_path		*path;
	char		*opt;

	opt = ft_strnew(13);
	if (opt)
	{
		path = parse_opt(opt, argv, argc);
		if (!path)
			path = path_add(path, ".", opt);
		path = path_srt(path, opt);
		ft_ls(path, opt);
		path_del(path);
		ft_strdel(&opt);
	}
	return (!opt ? MEM_ERR : 0);
}
