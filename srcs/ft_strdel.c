#include "../includes/libft.h"

void	ft_strdel(char **as)
{
	free(*as);
	*as = NULL;
}