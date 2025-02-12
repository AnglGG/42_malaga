/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:21:59 by anggalle          #+#    #+#             */
/*   Updated: 2024/06/23 22:06:51 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (i < n)
	{
		p[i] = c;
		i ++;
	}
	return (s);
}

/*
#include <stdio.h>
int main() {
    char str[] = "Hola que tal";
	char *result;

    result = memset(str, '-', 5);
    printf("Resultado de memset: %s\n", result);

	result = ft_memset(str, '-', 5);
    printf("Resultado de ft_memset: %s\n", result);

    return 0;
}
*/