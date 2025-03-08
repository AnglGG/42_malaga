/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:47:00 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/08 12:47:05 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *src, char *dst)
{
	char	*result;
	int		j;
	int		k;

	j = 0;
	k = ft_strlen(src) + ft_strlen(dst) + 1;
	result = (char *)malloc(sizeof(char) * k);
	if (result == NULL)
		return (NULL);
	k = 0;
	while (src[j] != '\0')
	{
		result[k] = src[j];
		j++;
		k++;
	}
	j = 0;
	while (dst[j] != '\0')
	{
		result[k] = dst[j];
		j++;
		k++;
	}
	result[k] = '\0';
	return (result);
}
