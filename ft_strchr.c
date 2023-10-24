#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	while (*src && *src != c)
		src++;
	if (*src == 0 && c != 0)
		return (NULL);
	return ((char *)src);
}
