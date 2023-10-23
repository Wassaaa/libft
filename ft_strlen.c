#include <string.h>

size_t ft_strlen(const char *str)
{
    size_t count;

    count = 0;
    while (*str++)
        count++;
    return (count);
}

// #include <stdio.h>
// int main()
// {
//     printf("%ld\n", ft_strlen("test"));
// }