/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:56:15 by anggalle          #+#    #+#             */
/*   Updated: 2024/07/05 13:15:54 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_arg(char type_arg, va_list args, t_flags flags)
{
	int	count;

	count = 0;
	if (type_arg == 's')
		count += ft_putstr(va_arg(args, char *), flags);
	else if (type_arg == 'c')
		count += ft_putchar(va_arg(args, int), flags);
	else if (type_arg == 'p')
		count += ft_puthex((uintptr_t)va_arg(args, void *), 0, 1, flags);
	else if (type_arg == 'd')
		count += ft_putnbr(va_arg(args, int), flags);
	else if (type_arg == 'i')
		count += ft_putnbr(va_arg(args, int), flags);
	else if (type_arg == 'u')
		count += ft_putnbr((unsigned int)va_arg(args, unsigned int), flags);
	else if (type_arg == 'x')
		count += ft_puthex(va_arg(args, uintptr_t), 0, 0, flags);
	else if (type_arg == 'X')
		count += ft_puthex(va_arg(args, uintptr_t), 1, 0, flags);
	else if (type_arg == '%')
		count += ft_putchar('%', flags);
	return (count);
}

int	is_bonus(char type_bonus)
{
	if (type_bonus == ' ' || type_bonus == '#' || type_bonus == '+'
		|| type_bonus == '0' || type_bonus == '-' || isdigit(type_bonus)
		|| type_bonus == '.')
		return (1);
	return (0);
}

int	check_bonus(const char **format, va_list args)
{
	if (**format == '-')
		return (ft_left_justification(format, args));
	else if (isdigit(**format))
		return (ft_right_justification(format, args));
	else if (**format == '.')
		return (ft_right_justification(format, args));
	return (0);
}

int	process_format(const char **format, va_list args, t_flags flags)
{
	int	count;

	count = 0;
	if (is_bonus(**format))
		count += check_bonus(format, args);
	else
		count += check_arg(**format, args, flags);
	(*format)++;
	return (count);
}

int	ft_printf(char const *format, ...)
{
	int		count;
	va_list	args;
	t_flags	flags;

	flags.print = 1;
	flags.zero = 0;
	flags.precision = -1;
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format++, 1);
			count ++;
		}
		else
		{
			format++;
			count += process_format(&format, args, flags);
		}
	}
	va_end(args);
	return (count);
}
