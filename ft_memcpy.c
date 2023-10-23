#include <string.h>

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    char *char_src;
    char *char_dest;

    char_src = (char *)src;
    char_dest = (char *)dest;
    while (n--)
        *char_dest++ = *char_src++;
    return (dest);
}
