#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr)
	{
		if (ft_isdigit(*nptr))
			number = number * 10 + (*nptr - '0');
		else
			return (number * sign);
		nptr++;
	}
	return (number * sign);
}
