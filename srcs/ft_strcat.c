#include "../includes/libft.h"

char *ft_strcat(char *dest, const char *src)
{
	size_t	dest_len;
	char	*dest_start;
	
	dest_start = dest;
	dest_len = ft_strlen(dest);
	dest += dest_len;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return dest_start;
}