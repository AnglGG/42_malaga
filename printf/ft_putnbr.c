/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:08:26 by anggalle          #+#    #+#             */
/*   Updated: 2024/07/05 13:06:35 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

int	ft_put_zeros(int num_zeros, t_flags flags)
{
	int	i;

	i = 0;
	while (i < num_zeros)
	{
		ft_putchar('0', flags);
		i++;
	}
	return (i);
}

int	handle_zero(t_flags flags)
{
	if (flags.precision == 0)
		return (0);
	ft_putchar('0', flags);
	return (1);
}

int	print_digits(long n, t_flags flags)
{
	int		count;
	char	digits[20];
	int		i;

	i = 0;
	count = 0;
	while (n > 0)
	{
		digits[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i--)
		count += ft_putchar(digits[i], flags);
	return (count);
}

int	ft_putnbr(long n, t_flags flags)
{
	int		count;
	int		num_zeros;

	count = 0;
	num_zeros = 0;
	if (n < 0)
	{
		count += ft_putchar('-', flags);
		n = -n;
	}
	if (flags.precision > -1)
	{
		num_zeros = flags.precision - ft_numlen(n);
		count += ft_put_zeros(num_zeros, flags);
	}
	if (n == 0)
		count += handle_zero(flags);
	count += print_digits(n, flags);
	return (count);
}
