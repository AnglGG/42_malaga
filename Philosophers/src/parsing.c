/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:04:41 by anggalle          #+#    #+#             */
/*   Updated: 2025/07/01 17:46:32 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_valid_positive_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_number_too_large(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 10)
		return (1);
	if (len < 10)
		return (0);
	if (ft_strncmp(str, "2147483647", 10) > 0)
		return (1);
	return (0);
}

int	strict_atoi(char *str)
{
	int		result;
	char	*trimmed;

	if (!is_valid_positive_number(str))
		return (-1);
	trimmed = str;
	if (*trimmed == '+')
		trimmed++;
	if (is_number_too_large(trimmed))
		return (-1);
	result = ft_atoi(trimmed);
	if (result < 0)
		return (-1);
	return (result);
}

void	validate_argument(char *arg, int min_value, char *param_name)
{
	int	value;

	value = strict_atoi(arg);
	if (value == -1)
		error_exit("Invalid number format");
	if (min_value == 1 && value == 0)
	{
		if (ft_strncmp(param_name, "philosophers", 12) == 0)
			error_exit("Number of philosophers must be greater than 0");
		else
			error_exit("Time values must be greater than 0");
	}
}

void	parse_arguments(int argc, char **argv, t_table *table)
{
	if (argc < 5 || argc > 6)
		error_exit("Invalid number of arguments");
	validate_argument(argv[1], 1, "philosophers");
	table->num_philos = strict_atoi(argv[1]);
	validate_argument(argv[2], 1, "time_to_die");
	table->time_to_die = strict_atoi(argv[2]);
	validate_argument(argv[3], 0, "time_to_eat");
	table->time_to_eat = strict_atoi(argv[3]);
	validate_argument(argv[4], 0, "time_to_sleep");
	table->time_to_sleep = strict_atoi(argv[4]);
	if (argc == 6)
	{
		validate_argument(argv[5], 0, "num_meals");
		table->num_meals = strict_atoi(argv[5]);
	}
	else
		table->num_meals = -1;
}
