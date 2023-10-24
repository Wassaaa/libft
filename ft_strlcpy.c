#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while (*src && (dstsize - 1) > 0)
	{
		*(dst++) = *(src++);
		dstsize--;
	}
	*dst = '\0';
	return (src_len);
}
