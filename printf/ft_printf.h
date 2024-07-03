/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:54:44 by anggalle          #+#    #+#             */
/*   Updated: 2024/07/03 09:53:31 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h> 
# include <stdarg.h>
# include <stdint.h>

int		ft_puthex(uintptr_t n, int is_uppercase, int include_prefix);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putnbr(long n);
int		ft_puthex(uintptr_t n, int mayusculas, int include_prefix);
int		ft_printf(char	const	*format, ...);

#endif