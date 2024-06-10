/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:24:56 by anggalle          #+#    #+#             */
/*   Updated: 2024/03/26 23:35:57 by anggalle         ###   ########.fr       */
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
		{
			return (str);
		}
		i ++;
		str ++;
	}
	if (s[i] == (char) c)
	{
		return (str);
	}
	return (NULL);
}
