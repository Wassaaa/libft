#include "libft.h"

// char	*ft_strcpy(char *dest, const char *src)
// {
// 	int	i;

// 	i = -1;
// 	while (src[++i])
// 		dest[i] = src[i];
// 	dest[i] = '\0';
// 	return (dest);
// }

char	*ft_strcpy(char *dest, const char *src)
{
	char *dest_start;

	dest_start = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_start);
}