/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:55:00 by anggalle          #+#    #+#             */
/*   Updated: 2025/07/14 15:56:46 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	initialize_start_times(t_table *table)
{
	int	i;

	table->start_time = get_current_time();
	i = 0;
	while (i < table->num_philos)
	{
		table->philos[i].last_meal_time = table->start_time;
		i++;
	}
}

void	signal_threads_start(t_table *table)
{
	pthread_mutex_lock(&table->ready_mutex);
	table->all_threads_ready = 1;
	pthread_mutex_unlock(&table->ready_mutex);
}
