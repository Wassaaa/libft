#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	char	*dest_start;

	dest_start = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_start);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	char	*new_start;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	new_start = new_str;
	ft_strcpy(new_str, s1);
	new_str += ft_strlen(s1);
	ft_strcpy(new_str, s2);
	return (new_start);
}
