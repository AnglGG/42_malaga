/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:45:14 by anggalle          #+#    #+#             */
/*   Updated: 2025/07/16 18:41:43 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hastack(const char **format, va_list args, t_flags flags)
{
	flags.prefix = 1;
	flags.zero = 2;
	(*format)++;
	if (**format == 'X')
		flags.prefix = 2;
	return (check_arg(**format, args, flags));
}
