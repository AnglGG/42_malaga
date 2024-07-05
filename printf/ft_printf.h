/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:54:44 by anggalle          #+#    #+#             */
/*   Updated: 2024/07/05 12:45:42 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h> 
# include <stdarg.h>
# include <stdint.h>
# include <ctype.h>

typedef struct s_flags
{
	int	print;
	int	zero;
	int	precision;
}	t_flags;

int		ft_puthex(uintptr_t n, int is_uppercase, int include_prefix,
			t_flags flags);
int		ft_putstr(char *str, t_flags flags);
int		ft_putchar(char c, t_flags flags);
int		ft_putnbr(long n, t_flags flags);
int		ft_put_zeros(int num_zeros, t_flags flags);
int		ft_printf(char	const	*format, ...);
int		check_arg(char type_arg, va_list args, t_flags flags);
int		ft_left_justification(const char **format, va_list args);
int		ft_right_justification(const char **format, va_list args);

#endif