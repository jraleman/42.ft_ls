#include "libft.h"

char	*ft_strlower(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + 32 : s[i];
	return (s);
}
