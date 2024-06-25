/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:54:44 by anggalle          #+#    #+#             */
/*   Updated: 2024/06/25 20:01:16 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf_utils(char format, va_list arg);
int		ft_putstr(char *str);
int		ft_putchr(char chr);
int		ft_printf(char	const	*format, ...);

#endif