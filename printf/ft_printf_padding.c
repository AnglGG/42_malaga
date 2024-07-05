/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:32:27 by anggalle          #+#    #+#             */
/*   Updated: 2024/07/05 13:10:48 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int		negative;
	long	number;

	number = 0;
	negative = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str ++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = -1;
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (number != 0)
			number *= 10;
		number += (*str - '0') * negative;
		str ++;
	}
	return ((int)number);
}

int	is_zero(const char *str)
{
	const char	*tmp;

	tmp = str;
	while (!isdigit(*tmp))
		tmp++;
	if (*tmp == '0')
		return (1);
	return (0);
}

int	calc_precision(const char *str)
{
	const char	*tmp;
	int			nbr;

	tmp = str;
	nbr = -1;
	while (isdigit(*tmp))
		tmp++;
	if (*tmp == '.')
	{
		tmp++;
		if (isdigit(*tmp))
			nbr = ft_atoi(tmp);
		else
			nbr = 0;
	}
	return (nbr);
}

int	ft_left_justification(const char **format, va_list args)
{
	int		total_tam;
	int		arg_tam;
	t_flags	flags;

	(*format)++;
	while (**format == '-')
		(*format) ++;
	flags.zero = is_zero(*format);
	flags.print = 1;
	flags.precision = calc_precision(*format);
	total_tam = ft_atoi(*format);
	while (isdigit(**format) || **format == '.')
		(*format)++;
	arg_tam = check_arg(**format, args, flags);
	while (arg_tam < total_tam)
	{
		if (flags.zero)
			arg_tam += ft_putchar('0', flags);
		else
			arg_tam += ft_putchar(' ', flags);
	}
	return (arg_tam);
}

int	ft_right_justification(const char **format, va_list args)
{
	int		total_tam;
	int		arg_tam;
	va_list	args_copy;
	t_flags	flags;

	va_copy(args_copy, args);
	flags.zero = is_zero(*format);
	flags.print = 0;
	flags.precision = calc_precision(*format);
	total_tam = ft_atoi(*format);
	while (isdigit(**format) || **format == '.')
		(*format)++;
	arg_tam = check_arg(**format, args_copy, flags);
	va_end(args_copy);
	flags.print = 1;
	while (arg_tam < total_tam)
	{
		if (flags.zero && flags.precision != 0)
			arg_tam += ft_putchar('0', flags);
		else
			arg_tam += ft_putchar(' ', flags);
	}
	check_arg(**format, args, flags);
	return (arg_tam);
}
