#include "libft.h"

static size_t count_digits(int n)
{
	size_t	digits;
	
	if (n == 0)
		return (1);
	digits = 0;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	size_t	i;
	size_t	digits;
	int		is_negative;

	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	digits = count_digits(n) + is_negative;
	nbr = ft_memalloc(digits + 1);
	if (!nbr)
		return (NULL);
	i = digits - 1;
	if (n == 0)
		nbr[i] = '0';
	while (n != 0)
	{
		nbr[i--] = '0' + ABS(n % 10);
		n /= 10;
	}
	if (is_negative)
		nbr[0] = '-';
	return (nbr);
}