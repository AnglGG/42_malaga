/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:01:17 by anggalle          #+#    #+#             */
/*   Updated: 2024/06/23 13:44:30 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	i = 0;
	s = (char *)src;
	d = (char *)dest;
	if (!n || dest == src)
		return (dest);
	while (i < n)
	{
		d[i] = s[i];
		i ++;
	}
	return (dest);
}
/*
#include <stdio.h>
int main()
{
	char phrase1[] = "Hola";
	const char *phrase2 = "a";
	char	*result;

	//función original
	result = memcpy(phrase1, phrase2, 3);
	printf("La diferencia es %s\n", result);
	
	result = ft_memcpy(phrase1, phrase2, 3);
	printf("La diferencia es %s\n", result);
}
*/