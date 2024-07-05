/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexadecimals.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:57:41 by anggalle          #+#    #+#             */
/*   Updated: 2024/07/05 12:56:14 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_hex_digit(uintptr_t digit, int is_uppercase)
{
	const char	*hex_min;
	const char	*hex_max;

	hex_min = "0123456789abcdef";
	hex_max = "0123456789ABCDEF";
	if (is_uppercase)
		return (hex_max[digit]);
	else
		return (hex_min[digit]);
}

int	add_prefix(int include_prefix, t_flags flags)
{
	if (include_prefix)
		return (ft_putstr("0x", flags));
	return (0);
}

int	handle_zero_case(int include_prefix, t_flags flags)
{
	int	count;
	int	num_zeros;

	num_zeros = 0;
	count = 0;
	if (flags.precision == 0)
		return (0);
	if (include_prefix)
	{
		if (flags.print)
			write(1, "(nil)", 5);
		return (5);
	}
	num_zeros = flags.precision - 1;
	count += ft_put_zeros(num_zeros, flags);
	return (count + ft_putchar('0', flags));
}

int	ft_puthex(uintptr_t n, int is_uppercase, int include_prefix, t_flags flags)
{
	char	buffer[16];
	int		count;
	int		i;
	int		num_zeros;

	count = 0;
	i = 0;
	if (n == 0)
		return (handle_zero_case(include_prefix, flags));
	count += add_prefix(include_prefix, flags);
	while (n > 0)
	{
		buffer[i++] = get_hex_digit(n % 16, is_uppercase);
		n /= 16;
	}
	if (flags.precision > -1)
	{
		num_zeros = flags.precision - i;
		count += ft_put_zeros(num_zeros, flags);
	}
	while (i-- > 0)
		count += ft_putchar(buffer[i], flags);
	return (count);
}
