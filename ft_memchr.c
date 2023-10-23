#include "libft.h"

void    *ft_memchr(const void *str, int c, size_t n)
{
	unsigned char   *c_str;

	c_str = (unsigned char *)str;
	while (n--)
	{
		if (*c_str == (unsigned char)c)
			return ((void *)c_str);
		c_str++;
	}
	return (NULL);
}
