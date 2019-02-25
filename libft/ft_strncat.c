#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	while ((i < n) && s2[i])
	{
		s1[i + j] = s2[i];
		i += 1;
	}
	s1[i + j] = '\0';
	return (s1);
}