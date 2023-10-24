#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc(ft_strlen(str) + 1);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
