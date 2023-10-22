#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	char	*start;

	new_str = ft_memalloc(ft_strlen(s) + 1);
	start = new_str;
	if (!new_str)
		return (NULL);
	while (*s)
		*new_str++ = f(*(s++));
	return (start);
}
