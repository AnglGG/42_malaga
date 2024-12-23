/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:32:27 by anggalle          #+#    #+#             */
/*   Updated: 2024/07/09 12:09:38 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_zero(const char *str)
{
	const char	*tmp;

	tmp = str;
	while (!ft_isdigit(*tmp))
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
	while (ft_isdigit(*tmp))
		tmp++;
	if (*tmp == '.')
	{
		tmp++;
		if (ft_isdigit(*tmp))
			nbr = ft_atoi(tmp);
		else
			nbr = 0;
	}
	return (nbr);
}

int	ft_left_justification(const char **format, va_list args, t_flags flags)
{
	int		total_tam;
	int		arg_tam;

	(*format)++;
	while (**format == '-')
		(*format)++;
	flags.zero = is_zero(*format);
	flags.print = 1;
	flags.precision = calc_precision(*format);
	total_tam = ft_atoi(*format);
	while (ft_isdigit(**format) || **format == '.')
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

void	configure_flags(t_flags *flags, const char *format)
{
	flags->zero = is_zero(format);
	flags->print = 0;
	flags->precision = calc_precision(format);
	if (flags->zero > 0)
		flags->neg = 0;
	if (flags->precision > -1 && flags->zero)
		flags->neg = 1;
}

int	ft_right_justification(const char **format, va_list args, t_flags flags)
{
	int		total_tam;
	int		arg_tam;
	va_list	args_copy;

	va_copy(args_copy, args);
	configure_flags(&flags, *format);
	total_tam = ft_atoi(*format);
	while (ft_isdigit(**format) || **format == '.' || **format == ' ')
		(*format)++;
	arg_tam = check_arg(**format, args_copy, flags);
	if (flags.zero > 0)
		flags.neg = 1;
	va_end(args_copy);
	flags.print = 1;
	while (arg_tam < total_tam)
	{
		if (flags.zero && flags.precision == -1)
			arg_tam += ft_putchar('0', flags);
		else
			arg_tam += ft_putchar(' ', flags);
	}
	check_arg(**format, args, flags);
	return (arg_tam);
}
