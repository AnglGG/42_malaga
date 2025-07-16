/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:54:00 by anggalle          #+#    #+#             */
/*   Updated: 2025/07/14 15:56:55 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_mutex_trio(t_table *table)
{
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&table->ready_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&table->print_mutex);
		return (-1);
	}
	if (pthread_mutex_init(&table->simulation_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&table->print_mutex);
		pthread_mutex_destroy(&table->ready_mutex);
		return (-1);
	}
	return (0);
}
