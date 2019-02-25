#include "libft.h"

int		ft_cisin(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			break ;
		else
			s += 1;
	}
	return (!*s ? 0 : 1);
}
