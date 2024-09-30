/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 23:30:43 by anggalle          #+#    #+#             */
/*   Updated: 2024/03/26 23:41:34 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	*dev_str;
	int		contador;

	i = 0;
	contador = 0;
	str = (char *)s;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			dev_str = str;
			contador ++;
		}
		i ++;
		str ++;
	}
	if (contador > 0)
		return (dev_str);
	if (s[i] == (char) c)
	{
		return (str);
	}
	return (NULL);
}
