#include "../includes/libft.h"

void *ft_memalloc(size_t size)
{
	char *area;

	area = (char *)malloc(size);
	if (!area)
		return (NULL);
	ft_bzero(area, size);
	return ((void *)area);
}