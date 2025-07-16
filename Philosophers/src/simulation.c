/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:00:00 by anggalle          #+#    #+#             */
/*   Updated: 2025/07/16 14:07:44 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	handle_single_philosopher(t_table *table)
{
	table->start_time = get_current_time();
	table->philos[0].last_meal_time = table->start_time;
	print_action(&table->philos[0], "has taken a fork");
	while (get_current_time() - table->start_time < table->time_to_die)
	{
		usleep(1000);
		if (is_simulation_ended(table))
			break ;
	}
	if (!is_simulation_ended(table))
	{
		set_simulation_ended(table);
		print_action(&table->philos[0], "died");
	}
}

static int	create_philosopher_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		if (pthread_create(&table->philos[i].thread_id, NULL,
				philosopher_routine, &table->philos[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

static int	create_monitor_thread(t_table *table)
{
	if (pthread_create(&table->monitor_thread, NULL,
			monitor_routine, table) != 0)
		return (1);
	return (0);
}

int	start_simulation(t_table *table)
{
	table->simulation_ended = 0;
	if (table->num_meals == 0)
		return (0);
	if (table->num_philos == 1)
	{
		handle_single_philosopher(table);
		return (0);
	}
	if (create_philosopher_threads(table) != 0)
		return (1);
	if (create_monitor_thread(table) != 0)
		return (1);
	initialize_start_times(table);
	signal_threads_start(table);
	return (0);
}

void	join_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		if (table->philos[i].thread_id != 0)
			pthread_join(table->philos[i].thread_id, NULL);
		i++;
	}
	if (table->monitor_thread != 0)
		pthread_join(table->monitor_thread, NULL);
}
