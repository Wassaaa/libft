#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new_str;
	char	*start_str;

	new_str = ft_memalloc(ft_strlen(s) + 1);
	if (!new_str)
		return (NULL);
	start_str = new_str;
	while (ft_isspace(*s))
		s++;
	while (*s)
		*new_str++ = *s++;
	while (ft_isspace(*--new_str))
		*new_str = '\0';
	return (start_str);
}
