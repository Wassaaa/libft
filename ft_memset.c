 #include <string.h>

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*temp_ptr;

	temp_ptr = ptr;
	while (n--)
		*temp_ptr++ = (unsigned char)c;
	return (ptr);
}
