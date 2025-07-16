/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:56:15 by anggalle          #+#    #+#             */
/*   Updated: 2025/07/16 18:40:46 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_arg(char type_arg, va_list args, t_flags flags)
{
	int	count;

	count = 0;
	if (type_arg == 's')
		count += ft_putstr(va_arg(args, char *), flags);
	else if (type_arg == 'c')
		count += ft_putchar(va_arg(args, int), flags);
	else if (type_arg == 'p')
	{
		flags.prefix = 1;
		count += ft_puthex((uintptr_t)va_arg(args, void *), 0, flags);
	}
	else if (type_arg == 'd')
		count += ft_putnbr(va_arg(args, int), flags);
	else if (type_arg == 'i')
		count += ft_putnbr(va_arg(args, int), flags);
	else if (type_arg == 'u')
		count += ft_putnbr((unsigned int)va_arg(args, unsigned int), flags);
	else if (type_arg == 'x')
		count += ft_puthex((unsigned int)va_arg(args, uintptr_t), 0, flags);
	else if (type_arg == 'X')
		count += ft_puthex((unsigned int)va_arg(args, uintptr_t), 1, flags);
	else if (type_arg == '%')
		count += ft_putchar('%', flags);
	return (count);
}

int	check_bonus(const char **format, va_list args, t_flags flags)
{
	if (**format == '-')
		return (ft_left_justification(format, args, flags));
	else if (ft_isdigit(**format))
		return (ft_right_justification(format, args, flags));
	else if (**format == '.')
		return (ft_right_justification(format, args, flags));
	else if (**format == '#')
		return (ft_hastack (format, args, flags));
	else if (**format == ' ')
	{
		flags.space = 1;
		return (ft_right_justification(format, args, flags));
	}
	else if (**format == '+')
	{
		flags.mas = 1;
		flags.space = 2;
		while (**format == '+')
			(*format)++;
		return (check_arg(**format, args, flags));
	}
	return (0);
}

int	process_format(const char **format, va_list args, t_flags flags)
{
	int	count;

	count = 0;
	if (**format == ' ' || **format == '#' || **format == '+'
		|| **format == '0' || **format == '-' || ft_isdigit(**format)
		|| **format == '.')
		count += check_bonus(format, args, flags);
	else
		count += check_arg(**format, args, flags);
	(*format)++;
	return (count);
}

void	initialize_flags(t_flags *flags)
{
	flags->print = 1;
	flags->zero = 0;
	flags->precision = -1;
	flags->neg = 0;
	flags->prefix = 0;
	flags->space = 0;
	flags->mas = 0;
}

int	ft_printf(char const *format, ...)
{
	int		count;
	va_list	args;
	t_flags	flags;

	initialize_flags(&flags);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		flags.neg = 0;
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
