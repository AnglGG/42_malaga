/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:24:56 by anggalle          #+#    #+#             */
/*   Updated: 2024/06/24 11:53:33 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (str);
		i ++;
		str ++;
	}
	if (s[i] == (char) c)
		return (str);
	return (NULL);
}

/*
int main()
{
	const char str[] = "Hola que tal";
	int c = 'o';
	char *result;

	result = ft_strchr(str, c);
	printf("El resultado es:  %ld\n", (result-str));
	
}
*/