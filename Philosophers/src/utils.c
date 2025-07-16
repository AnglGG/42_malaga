/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:04:47 by anggalle          #+#    #+#             */
/*   Updated: 2025/07/14 15:50:59 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_small_timing_case(t_table *table)
{
	if (table->time_to_die <= 250)
		return (1);
	if (table->time_to_die <= 400 && table->time_to_eat <= 150)
		return (1);
	if (table->time_to_die <= 400 && table->time_to_sleep <= 150)
		return (1);
	return (0);
}

int	is_simulation_ended(t_table *table)
{
	int	ended;

	pthread_mutex_lock(&table->simulation_mutex);
	ended = table->simulation_ended;
	pthread_mutex_unlock(&table->simulation_mutex);
	return (ended);
}

void	set_simulation_ended(t_table *table)
{
	pthread_mutex_lock(&table->simulation_mutex);
	table->simulation_ended = 1;
	pthread_mutex_unlock(&table->simulation_mutex);
}

void	ft_usleep(long usec, t_table *table)
{
	long	start;
	long	elapsed;

	start = get_current_time_usec();
	while (!is_simulation_ended(table))
	{
		elapsed = get_current_time_usec() - start;
		if (elapsed >= usec)
			break ;
		if (usec - elapsed > 1000)
			usleep(500);
		else
			usleep(100);
	}
}
