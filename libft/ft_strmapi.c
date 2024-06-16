/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:32:52 by anggalle          #+#    #+#             */
/*   Updated: 2024/06/16 17:37:15 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	res = malloc((ft_strlen(s + 1)), sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while ((int)i < ft_strlen(s))
	{
		res[i] = (*f)(i, s[i]);
		i ++;
	}
	res[i] = 0;
	return (res);
}
