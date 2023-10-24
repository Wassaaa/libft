#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c_s1;
	unsigned char	*c_s2;

	c_s1 = (unsigned char *)s1;
	c_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*c_s1 != *c_s2)
			return ((int)*c_s1 - (int)*c_s2);
		c_s1++;
		c_s2++;
	}
	return (0);
}
