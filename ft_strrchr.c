#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	size_t	len;

	len = ft_strlen(src);
	while (len && src[len] != c)
		len--;
	if (len == 0 && c != src[len])
		return (0);
	return ((char *)&src[len]);
}
