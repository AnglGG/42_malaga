/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:10:00 by anggalle          #+#    #+#             */
/*   Updated: 2025/07/06 22:37:30 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	cleanup_philosophers(t_table *table)
{
	int	i;

	if (table->philos)
	{
		i = 0;
		while (i < table->num_philos)
		{
			pthread_mutex_destroy(&table->philos[i].meal_mutex);
			i++;
		}
		free(table->philos);
		table->philos = NULL;
	}
}

static void	cleanup_forks(t_table *table)
{
	int	i;

	if (table->forks)
	{
		i = 0;
		while (i < table->num_philos)
		{
			pthread_mutex_destroy(&table->forks[i].mutex);
			i++;
		}
		free(table->forks);
		table->forks = NULL;
	}
}

void	cleanup_table(t_table *table)
{
	cleanup_philosophers(table);
	cleanup_forks(table);
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->ready_mutex);
	pthread_mutex_destroy(&table->simulation_mutex);
}
