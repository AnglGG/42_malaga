/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:54:44 by anggalle          #+#    #+#             */
/*   Updated: 2024/07/06 18:28:46 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h> 
# include <stdarg.h>
# include <stdint.h>
# include <ctype.h>
# include <stdio.h>

typedef struct s_flags
{
	int	print;
	int	zero;
	int	precision;
	int	neg;
	int	prefix;
	int	space;
	int	mas;
}	t_flags;

int		ft_atoi(const char *str);
int		ft_numlen(long num);
int		ft_puthex(uintptr_t n, int is_uppercase, t_flags flags);
int		ft_putstr(char *str, t_flags flags);
int		ft_putchar(char c, t_flags flags);
int		ft_putnbr(long n, t_flags flags);
int		ft_put_zeros(int num_zeros, t_flags flags);
int		ft_hastack(const char **format, va_list args, t_flags flags);
int		ft_printf(char	const	*format, ...);
int		check_arg(char type_arg, va_list args, t_flags flags);
int		ft_left_justification(const char **format, va_list args);
int		ft_right_justification(const char **format, va_list args,
			t_flags flags);

#endif