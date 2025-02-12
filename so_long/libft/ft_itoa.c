/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:55:46 by anggalle          #+#    #+#             */
/*   Updated: 2024/06/23 12:55:49 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_nbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		count ++;
	}
	if (nbr == 0)
		count ++;
	while (nbr != 0)
	{
		nbr /= 10;
		count ++;
	}
	return (count);
}

char	*pre_conv(int len)
{
	char	*tmp;

	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[0] = '0';
	return (tmp);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*result;
	long	nbr;

	nbr = n;
	len = len_nbr(nbr);
	result = pre_conv(len);
	if (!result)
		return (NULL);
	i = len - 1;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr != 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr /= 10;
		i --;
	}
	if (n < 0)
		result[0] = '-';
	result[len] = '\0';
	return (result);
}

/*
#include <stdio.h>

int main() {
	int nbr = -2147483648;

	char *numero_ft = ft_itoa(nbr);
	printf("El número con ft_itoa es: %s\n", numero_ft);
}
*/