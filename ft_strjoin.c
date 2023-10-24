#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	char	*new_start;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = ft_memalloc(len + 1);
	if (!new_str)
		return (NULL);
	new_start = new_str;
	ft_strcpy(new_str, s1);
	new_str += ft_strlen(s1);
	ft_strcpy(new_str, s2);
	return (new_start);
}
