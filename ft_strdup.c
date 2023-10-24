#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		i;

	i = -1;
	dup = (char *)malloc(ft_strlen(str) + 1);
	while (str[++i])
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}
