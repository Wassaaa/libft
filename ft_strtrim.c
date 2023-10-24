#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	char	*start_str;
	size_t	len;

	len = 0;
	len = ft_strlen(s1);
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	start_str = new_str;
	new_str[len] = '\0';
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (*s1)
		*(new_str++) = *(s1++);
	new_str--;
	while (ft_strchr(set, *new_str))
	{
		*new_str = '\0';
		new_str--;
	}
	return (start_str);
}
