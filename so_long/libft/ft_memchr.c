/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 23:55:03 by anggalle          #+#    #+#             */
/*   Updated: 2024/06/23 22:11:40 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	caracter;

	i = 0;
	str = (unsigned char *) s;
	caracter = (unsigned char) c;
	while (i < n)
	{
		if (str[i] == caracter)
			return (str + i);
		i ++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main()
{
	int c = 'H';
	const char *phrase = "Hola mundo";
	char	*result;
	result = ft_memchr(phrase, c, sizeof(phrase));
	if (result != NULL)
		printf("Character '%c' found at position: %ld\n", c, result - phrase);
	else
		printf("Character '%c' not found.\n", c);
	//función original
	result = memchr(phrase, c, sizeof(phrase));
	if (result != NULL)
		printf("Character '%c' found at position: %ld\n", c, result - phrase);
	else
		printf("Character '%c' not found.\n", c);
}
*/