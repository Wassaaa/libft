#include "../includes/libft.h"

char *ft_strncpy(char *dest, const char *src, size_t n)
{
	int	i;

	i = -1;
	while (++i < n && src[i])
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}