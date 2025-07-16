/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:08:26 by anggalle          #+#    #+#             */
/*   Updated: 2025/07/16 18:43:15 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	int	count;

	count = 0;
	if (flags.precision == 0)
		return (count);
	if (flags.space == 1)
		count += ft_putchar(' ', flags);
	if (flags.mas == 1)
		count += ft_putchar('+', flags);
	count += ft_putchar('0', flags);
	return (count);
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
	if (flags.space == 1)
		count += ft_putchar(' ', flags);
	if (flags.space == 2)
	{
		if (flags.mas == 1)
			count += ft_putchar('+', flags);
	}
	while (i--)
		count += ft_putchar(digits[i], flags);
	return (count);
}

int	handle_negative(long *n, t_flags *flags)
{
	int	count;

	count = 0;
	flags->space = 0;
	if (flags->neg == 0 && flags->zero)
		write(1, "-", 1);
	else if (flags->zero == 0 || (flags->zero && flags->precision > -1))
		ft_putchar('-', *flags);
	*n = -(*n);
	count += 1;
	return (count);
}

int	ft_putnbr(long n, t_flags flags)
{
	int		count;
	int		num_zeros;

	count = 0;
	num_zeros = 0;
	if (n < 0)
		count += handle_negative(&n, &flags);
	if (flags.precision > -1)
	{
		num_zeros = flags.precision - ft_numlen(n);
		count += ft_put_zeros(num_zeros, flags);
	}
	if (n == 0)
	{
		count += handle_zero(flags);
		flags.space = 0;
	}
	count += print_digits(n, flags);
	return (count);
}
