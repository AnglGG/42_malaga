/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:15:33 by anggalle          #+#    #+#             */
/*   Updated: 2024/03/09 00:39:26 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <string.h>
#include <unistd.h>
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	if (!n || dest == src)
		return (dest);
	while (n > 0)
	{
		d[n - 1] = s[n - 1];
		n --;
	}
	return (dest);
}
/*
int		main()
{
    char src[] = "HOLAAA";
	char dst[] = "holaaaa";
	size_t len = 7;
	write(1, ft_memmove(dst, src, len), 8);
	write(1, "\n", 1);
	write(1, memmove(dst, src, len), 8);
	write(1, "\n", 1);
    return 0;
}
*/