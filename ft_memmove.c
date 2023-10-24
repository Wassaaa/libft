#include <string.h>
#include <stdlib.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*c_src;
	char		*temp;

	c_src = (char *)src;
	temp = dest;
	if (dest <= src)
		while (n--)
			*temp++ = *c_src++;
	else
	{
		temp += n;
		c_src += n;
		while (n--)
			*--temp = *--c_src;
	}
	return (dest);
}
