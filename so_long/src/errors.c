/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:52:16 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/13 19:19:19 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void error_and_exit(const char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}
