/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexadecimals.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:57:41 by anggalle          #+#    #+#             */
/*   Updated: 2024/07/03 10:13:44 by anggalle         ###   ########.fr       */
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

int	add_prefix(int include_prefix)
{
	if (include_prefix)
		return (ft_putstr("0x"));
	return (0);
}

int	handle_zero_case(int include_prefix)
{
	int	count;

	count = 0;
	if (include_prefix)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	return (count + ft_putchar('0'));
}

int	ft_puthex(uintptr_t n, int is_uppercase, int include_prefix)
{
	char	buffer[16];
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (n == 0)
		return (handle_zero_case(include_prefix));
	count += add_prefix(include_prefix);
	while (n > 0)
	{
		buffer[i++] = get_hex_digit(n % 16, is_uppercase);
		n /= 16;
	}
	while (i-- > 0)
		count += ft_putchar(buffer[i]);
	return (count);
}
