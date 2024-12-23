/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:09:38 by anggalle          #+#    #+#             */
/*   Updated: 2024/06/23 22:11:46 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i ++;
	}
	return (0);
}

/*
#include <stdio.h>
int main()
{
	const char *phrase1 = "Hola mundo";
	const char *phrase2 = "Hola";
	int	result;
	result = ft_memcmp(phrase1, phrase2, sizeof(phrase1));
	printf("La diferencia es %d\n", result);
	
	//función original
	result = memcmp(phrase1, phrase2, sizeof(phrase1));
	printf("La diferencia es %d\n", result);
}
*/