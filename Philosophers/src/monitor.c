/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:00:00 by anggalle          #+#    #+#             */
/*   Updated: 2025/07/14 15:15:35 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	should_philosopher_die(t_philo *philo)
{
	long	current_time;
	long	time_since_meal;
	int		is_eating;

	pthread_mutex_lock(&philo->meal_mutex);
	current_time = get_current_time();
	time_since_meal = current_time - philo->last_meal_time;
	is_eating = philo->eating;
	pthread_mutex_unlock(&philo->meal_mutex);
	return (time_since_meal > philo->table->time_to_die && !is_eating);
}

static int	should_philosopher_die_unlocked(t_philo *philo)
{
	long	current_time;
	long	time_since_meal;
	int		is_eating;

	current_time = get_current_time();
	time_since_meal = current_time - philo->last_meal_time;
	is_eating = philo->eating;
	return (time_since_meal > philo->table->time_to_die && !is_eating);
}

int	all_philosophers_fed(t_table *table)
{
	int	i;
	int	fed_count;

	if (table->num_meals <= 0)
		return (0);
	fed_count = 0;
	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_lock(&table->philos[i].meal_mutex);
		if (table->philos[i].meals_count >= table->num_meals)
			fed_count++;
		pthread_mutex_unlock(&table->philos[i].meal_mutex);
		i++;
	}
	return (fed_count == table->num_philos);
}

static int	check_deaths(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_lock(&table->philos[i].meal_mutex);
		if (should_philosopher_die_unlocked(&table->philos[i]))
		{
			pthread_mutex_unlock(&table->philos[i].meal_mutex);
			if (!is_simulation_ended(table))
			{
				set_simulation_ended(table);
				print_action(&table->philos[i], "died");
			}
			return (1);
		}
		pthread_mutex_unlock(&table->philos[i].meal_mutex);
		i++;
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		ready;

	table = (t_table *)arg;
	ready = 0;
	while (!ready)
	{
		pthread_mutex_lock(&table->ready_mutex);
		ready = table->all_threads_ready;
		pthread_mutex_unlock(&table->ready_mutex);
	}
	while (!is_simulation_ended(table))
	{
		if (check_deaths(table) || all_philosophers_fed(table))
		{
			set_simulation_ended(table);
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}
