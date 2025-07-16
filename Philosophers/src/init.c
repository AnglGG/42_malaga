/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:00:00 by anggalle          #+#    #+#             */
/*   Updated: 2025/07/14 15:52:46 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	init_forks(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(t_fork) * table->num_philos);
	if (!table->forks)
		return (-1);
	i = 0;
	while (i < table->num_philos)
	{
		table->forks[i].id = i;
		if (pthread_mutex_init(&table->forks[i].mutex, NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&table->forks[i].mutex);
			free(table->forks);
			table->forks = NULL;
			return (-1);
		}
		i++;
	}
	return (0);
}

static void	init_philo_data(t_table *table, int i)
{
	table->philos[i].id = i + 1;
	table->philos[i].meals_count = 0;
	table->philos[i].eating = 0;
	table->philos[i].finished_eating = 0;
	table->philos[i].last_meal_time = 0;
	table->philos[i].thread_id = 0;
	table->philos[i].table = table;
	table->philos[i].left_fork = &table->forks[i];
	table->philos[i].right_fork = &table->forks[(i + 1) % table->num_philos];
}

static int	init_philosophers(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo) * table->num_philos);
	if (!table->philos)
		return (-1);
	i = 0;
	while (i < table->num_philos)
	{
		init_philo_data(table, i);
		if (pthread_mutex_init(&table->philos[i].meal_mutex, NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&table->philos[i].meal_mutex);
			free(table->philos);
			table->philos = NULL;
			return (-1);
		}
		i++;
	}
	return (0);
}

int	init_table(t_table *table)
{
	table->simulation_ended = 0;
	table->all_threads_ready = 0;
	table->monitor_thread = 0;
	table->start_time = 0;
	if (init_mutex_trio(table) != 0)
		return (-1);
	if (init_forks(table) != 0)
	{
		pthread_mutex_destroy(&table->print_mutex);
		pthread_mutex_destroy(&table->ready_mutex);
		pthread_mutex_destroy(&table->simulation_mutex);
		return (-1);
	}
	if (init_philosophers(table) != 0)
	{
		cleanup_table(table);
		return (-1);
	}
	return (0);
}
