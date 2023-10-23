#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*temp_str;

	temp_str = str;
	while (n--)
		*temp_str++ = '\0';
}