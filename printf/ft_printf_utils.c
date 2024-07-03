/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:12:05 by anggalle          #+#    #+#             */
/*   Updated: 2024/07/03 09:54:00 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i ++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(long num)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		i += ft_putchar('-');
		i += ft_putnbr(-num);
	}
	else
	{
		if (num > 9)
		{
			i += ft_putnbr(num / 10);
			i += ft_putnbr(num % 10);
		}
		else
			i += ft_putchar(num + '0');
	}
	return (i);
}

