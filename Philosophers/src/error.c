/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:00:00 by anggalle          #+#    #+#             */
/*   Updated: 2025/06/27 00:55:43 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	error_exit(char *message)
{
	printf("Error: %s\n", message);
	printf("Usage: ./philo <philos> <die> <eat> <sleep> [meals]\n");
	exit(EXIT_FAILURE);
}
