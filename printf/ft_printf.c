/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:56:15 by anggalle          #+#    #+#             */
/*   Updated: 2024/07/03 10:19:52 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_arg(char type_arg, va_list args)
{
	int	count;

	count = 0;
	if (type_arg == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (type_arg == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (type_arg == 'p')
		count += ft_puthex((uintptr_t)va_arg(args, void *), 0, 1);
	else if (type_arg == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (type_arg == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (type_arg == 'u')
		count += ft_putnbr((unsigned int)va_arg(args, unsigned int));
	else if (type_arg == 'x')
		count += ft_puthex(va_arg(args, uintptr_t), 0, 0);
	else if (type_arg == 'X')
		count += ft_puthex(va_arg(args, uintptr_t), 1, 0);
	else if (type_arg == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
		{
			i++;
			count += check_arg(format[i], args) - 1;
		}
		i ++;
		count ++;
	}
	va_end(args);
	return (count);
}
