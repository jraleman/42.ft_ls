#include "ft_printf.h"

void	ft_replace(char *s, char c1, char c2, int len)
{
	int count;

	count = 0;
	while (count < len)
	{
		if (s[count] == c1)
		{
			s[count] = c2;
			return ;
		}
		count++;
	}
}

int		lenall(t_printf *lst)
{
	int nb;

	nb = 0;
	while (lst)
	{
		nb += lst->len;
		lst = lst->next;
	}
	return (nb);
}
