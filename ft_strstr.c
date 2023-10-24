#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle,
				ft_strlen(needle)) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return ('\0');
}
