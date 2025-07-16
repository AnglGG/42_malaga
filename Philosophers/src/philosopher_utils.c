/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:52:00 by anggalle          #+#    #+#             */
/*   Updated: 2025/07/16 14:21:53 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	wait_for_start_signal(t_philo *philo)
{
	int	ready;

	ready = 0;
	while (!ready)
	{
		pthread_mutex_lock(&philo->table->ready_mutex);
		ready = philo->table->all_threads_ready;
		pthread_mutex_unlock(&philo->table->ready_mutex);
	}
}

void	philosopher_lifecycle(t_philo *philo)
{
	while (!is_simulation_ended(philo->table))
	{
		if (philo->table->num_meals > 0 && philo->meals_count
			>= philo->table->num_meals)
		{
			pthread_mutex_lock(&philo->meal_mutex);
			philo->finished_eating = 1;
			pthread_mutex_unlock(&philo->meal_mutex);
			break ;
		}
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		sleep_and_think(philo);
	}
}

long	get_initial_delay(t_philo *philo)
{
	if (philo->table->num_meals > 0)
		return ((philo->table->time_to_eat / 2) * 1000);
	if (philo->table->num_philos == 2)
		return ((philo->table->time_to_eat + 10) * 1000);
	else if (is_small_timing_case(philo->table))
		return ((philo->table->time_to_eat * philo->id
				/ philo->table->num_philos) * 1000);
	else
		return ((philo->table->time_to_eat / 2) * 1000);
}

long	calculate_think_time(t_philo *philo)
{
	long	think_time;

	if (philo->table->num_philos % 2 == 0)
		return (0);
	think_time = (philo->table->time_to_eat * 2 - philo->table->time_to_sleep);
	if (think_time < 0)
		think_time = 0;
	return (think_time * 1000);
}
