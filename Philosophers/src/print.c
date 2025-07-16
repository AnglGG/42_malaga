/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:20:00 by anggalle          #+#    #+#             */
/*   Updated: 2025/07/06 22:38:07 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_action(t_philo *philo, const char *action)
{
	long	timestamp;

	pthread_mutex_lock(&philo->table->print_mutex);
	if (is_simulation_ended(philo->table) && ft_strncmp(action, "died", 4) != 0)
	{
		pthread_mutex_unlock(&philo->table->print_mutex);
		return ;
	}
	timestamp = get_current_time() - philo->table->start_time;
	printf("%ld %d %s\n", timestamp, philo->id, action);
	pthread_mutex_unlock(&philo->table->print_mutex);
}
