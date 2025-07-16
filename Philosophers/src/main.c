/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:00:00 by anggalle          #+#    #+#             */
/*   Updated: 2025/07/14 15:15:38 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	parse_arguments(argc, argv, &table);
	if (init_table(&table) != 0)
	{
		error_exit("Failed to initialize table");
		return (1);
	}
	if (start_simulation(&table) != 0)
	{
		cleanup_table(&table);
		error_exit("Failed to start simulation");
		return (1);
	}
	join_threads(&table);
	cleanup_table(&table);
	return (0);
}
