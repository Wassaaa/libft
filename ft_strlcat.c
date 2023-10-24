#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	offset;
	size_t	s_index;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	offset = d_len;
	s_index = 0;
	if (size <= d_len)
		return (size + s_len);
	while (*(src+s_index) && s_index < size - d_len - 1)
		*(dest + offset++) = *(src + s_index++);
	*(dest + offset) = '\0';
	return (d_len + s_len);
}
