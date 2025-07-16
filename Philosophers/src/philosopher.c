/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:00:00 by anggalle          #+#    #+#             */
/*   Updated: 2025/07/16 14:18:40 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->right_fork->mutex);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(&philo->left_fork->mutex);
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(&philo->right_fork->mutex);
		print_action(philo, "has taken a fork");
	}
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->eating = 1;
	philo->last_meal_time = get_current_time();
	philo->meals_count++;
	pthread_mutex_unlock(&philo->meal_mutex);
	print_action(philo, "is eating");
	ft_usleep(philo->table->time_to_eat * 1000, philo->table);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->meal_mutex);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
}

void	sleep_and_think(t_philo *philo)
{
	long	think_time;

	print_action(philo, "is sleeping");
	ft_usleep(philo->table->time_to_sleep * 1000, philo->table);
	think_time = calculate_think_time(philo);
	if (think_time > 0)
	{
		print_action(philo, "is thinking");
		ft_usleep(think_time, philo->table);
	}
	else
		print_action(philo, "is thinking");
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;
	long	initial_delay;

	philo = (t_philo *)arg;
	wait_for_start_signal(philo);
	if (philo->id % 2 == 0)
	{
		print_action(philo, "is thinking");
		initial_delay = get_initial_delay(philo);
		ft_usleep(initial_delay, philo->table);
	}
	philosopher_lifecycle(philo);
	return (NULL);
}
