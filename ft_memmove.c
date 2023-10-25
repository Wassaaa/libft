/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:17:12 by aklein            #+#    #+#             */
/*   Updated: 2023/10/25 15:17:33 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*c_src;
	char		*temp;

	c_src = (char *)src;
	temp = dst;
	if (dst <= src)
		while (len--)
			*temp++ = *c_src++;
	else
	{
		temp += len;
		c_src += len;
		while (len--)
			*--temp = *--c_src;
	}
	return (dst);
}
