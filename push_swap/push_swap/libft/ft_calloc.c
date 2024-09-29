/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:49:34 by anggalle          #+#    #+#             */
/*   Updated: 2024/06/23 12:40:19 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = malloc(count * size);
	if (tmp == 0)
	{
		return (NULL);
	}
	while (i < (count * size))
	{
		tmp[i] = 0;
		i ++;
	}
	return (tmp);
}

/*
#include <stdio.h>
int main()
{
	size_t count = 10;
	size_t size = sizeof(int);
	int *array;
	int i;
	
	array = (int *)ft_calloc(count, size);
	if (array == NULL)
	{
		printf("Fallo");
		return (1);
	}
	else{
		for (i = 0; i < count; i ++)
		{
			if (array[i] != 0)
			{
				printf("El array no está inicializado a 0");
				return(1);
			}
		}
	}
	printf("La función funcionó correctamente\n");
}
*/