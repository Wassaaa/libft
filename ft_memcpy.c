/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:15:49 by aklein            #+#    #+#             */
/*   Updated: 2023/10/25 15:20:13 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*char_src;
	char	*char_dest;

	char_src = (char *)src;
	char_dest = (char *)dst;
	while (n--)
		*char_dest++ = *char_src++;
	return (dst);
}
