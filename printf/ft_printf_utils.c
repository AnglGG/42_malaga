/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:12:05 by anggalle          #+#    #+#             */
/*   Updated: 2024/06/26 15:42:45 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
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

int	counter(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i ++;
	while (n > 0)
	{
		n /= 16;
		i ++;
	}
	return (i);
}

int	ft_puthex(uintptr_t n, int mayusculas)
{
	char	*hex_may;
	char	*hex_min;
	char	*result;
	int		i;
	int		cont;

	hex_may = "0123456789ABCDEF";
	hex_min = "0123456789abcdef";
	i = counter(n);
	result = malloc(i * sizeof(char));
	cont = i;
	if (n == 0)
		result[0] = '0';
	while (n > 0)
	{
		if (mayusculas == 1)
			result[i - 1] = hex_may[n % 16];
		else
			result[i - 1] = hex_min[n % 16];
		i --;
		n /= 16;
	}
	result[cont] = '\0';
	ft_putstr(result);
	return (cont);
}
