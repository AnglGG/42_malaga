/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:12:05 by anggalle          #+#    #+#             */
/*   Updated: 2024/07/05 12:37:43 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str, t_flags flags)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (flags.precision >= 6 || flags.precision == -1)
		{
			if (flags.print)
				write(1, "(null)", 6);
			return (6);
		}
		return (0);
	}
	while (str[i] && (flags.precision > i || flags.precision == -1))
	{
		if (flags.print)
		{
			if (flags.precision == -1)
				write(1, &str[i], 1);
			else if (flags.precision > i)
				write(1, &str[i], 1);
		}
		i ++;
	}
	return (i);
}

int	ft_putchar(char c, t_flags flags)
{
	if (flags.print == 1)
	{
		write(1, &c, 1);
	}
	return (1);
}
