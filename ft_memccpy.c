#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n--)
		if (*(unsigned char *)src != (unsigned char)c)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
		else
			return ((unsigned char *)dest + 1);
	return (NULL);
}
