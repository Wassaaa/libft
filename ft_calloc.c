#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*my_calloc;

	my_calloc = (char *)malloc(count * size);
	if (!my_calloc)
		return (NULL);
	ft_bzero(my_calloc, count * size);
	return ((void *)my_calloc);
}
