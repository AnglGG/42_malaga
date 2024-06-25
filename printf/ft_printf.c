/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:56:15 by anggalle          #+#    #+#             */
/*   Updated: 2024/06/25 20:06:21 by anggalle         ###   ########.fr       */
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
		count += ft_putchr(va_arg(args, int));
	// else if (type_arg == 'p')
	// 	print_pointer(args, count);
	// else if (type_arg == 'd')
	// 	print_int(args, count);
	// else if (type_arg == 'i')
	// 	print_base10(args, count);
	// else if (type_arg == 'u')
	// 	print_base10_no_mark(args, count);
	// else if (type_arg == 'x')
	// 	print_base16_min(args, count);
	// else if (type_arg == 'X')
	// 	print_base16_max(args, count);
	// else if (type_arg == '%')
	// 	print_porc(args, count);
	return (count);
}

int	ft_printf(const char *format, ...)
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

// #include <stdio.h>
// int main()
// {
// 	int contador = ft_printf("Hola me llamo: %s", "Angel");
// 	printf("\n%d\n", contador);
// 	contador = printf("Hola me llamo: %s", "Angel");
// 	printf("\n%d\n", contador);
	
// }