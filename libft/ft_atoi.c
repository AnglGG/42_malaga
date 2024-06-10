/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:49:32 by anggalle          #+#    #+#             */
/*   Updated: 2024/03/28 01:08:37 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	negative;
	int	number;

	number = 0;
	negative = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str ++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = -1;
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (number != 0)
			number *= 10;
		number += (*str - '0') * negative;
		str ++;
	}
	return (number);
}
