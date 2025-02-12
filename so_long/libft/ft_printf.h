/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:16:03 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/09 17:16:05 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                              FT_PRINTF.H                                 */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h> 
# include <stdarg.h>
# include <stdint.h>

/* Estructura de flags para ft_printf */
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
int		ft_printf(char const *format, ...);
int		check_arg(char type_arg, va_list args, t_flags flags);
int		ft_left_justification(const char **format, va_list args, t_flags flags);
int		ft_isdigit(int c);
int		ft_right_justification(const char **format, va_list args, t_flags flags);

#endif
