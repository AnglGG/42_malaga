/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:56:33 by anggalle          #+#    #+#             */
/*   Updated: 2024/06/23 00:47:30 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;
	size_t	i;

	p = (char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i ++;
	}
}

/*
#include <stdio.h>

void print_memory(const void *mem, size_t n)
{
    const unsigned char *p = mem;
    for (size_t i = 0; i < n; i++)
    {
        printf("%02x ", p[i]);
    }
    printf("\n");
}

int main()
{
    char *phrase = NULL;

    printf("Original phrase: %s\n", phrase);

    // Using bzero
    //bzero(phrase, 4);
    printf("After bzero: %s\n", phrase);
    print_memory(phrase, sizeof(phrase));

    // Reset phrase for next test
    strcpy(phrase, "Hello World");

    // Using ft_bzero
    ft_bzero(phrase, 4);
    printf("After ft_bzero: %s\n", phrase);
    print_memory(phrase, sizeof(phrase));

    return 0;
}
*/