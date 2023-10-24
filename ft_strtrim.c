#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new_str;
	char	*start_str;
	size_t	len;

	len = ft_strlen(s);
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	start_str = new_str;
	new_str[len] = '\0';
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	while (*s)
		*new_str++ = *s++;
	new_str--;
	while (*new_str == 32 || (*new_str >= 9 && *new_str <= 13))
	{
		*new_str = '\0';
		new_str--;
	}
	return (start_str);
}
