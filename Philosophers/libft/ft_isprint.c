/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:35:33 by anggalle          #+#    #+#             */
/*   Updated: 2024/06/22 13:29:01 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	int	isprint;

	isprint = 0;
	if (c >= 32 && c <= 126)
	{
		isprint = 1;
	}
	return (isprint);
}

/* Comprobación de que si es mayor que 126 no es un caracter imprimible
#include <ctype.h>
#include <stdio.h>

int main() {
    unsigned char ch = 200; // Caracter en la tabla ASCII extendida

    if (isprint(ch)) {
        printf("%c es un carácter imprimible.\n", ch);
    } else {
        printf("%c no es un carácter imprimible.\n", ch);
    }

    return 0;
}
*/