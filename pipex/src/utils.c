/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:53:13 by anggalle          #+#    #+#             */
/*   Updated: 2024/12/22 20:42:14 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void get_command(int argc, char **argv)
{
	char *args[128];
	if (argc != 5)
	{
		ft_printf("Error en la introducción de comandos\n");
		exit(-1);
	}
	args = ft_split(argv, ' ');
}