#include "ft_ls.h"

/*
** If the numbers are equal, returns the difference between the strings.
** If not, return the difference between the numbers.
*/

int			ft_int_str_cmp(int a, int b, char *s1, char *s2)
{
	return (a == b ? ft_strcmp(s1, s2) : a - b);
}