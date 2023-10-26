/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:39:46 by aklein            #+#    #+#             */
/*   Updated: 2023/10/26 17:43:49 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	static int	iteration = 1;

	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n != 0)
	{
		iteration = 0;
		ft_putnbr_fd(ABS(n / 10), fd);
		ft_putchar_fd(ABS(n % 10) + '0', fd);
	}
	else if (iteration)
		ft_putchar_fd('0', fd);
}
