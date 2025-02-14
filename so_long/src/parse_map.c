/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:54:11 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/13 17:58:52 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_rectangular(char **map)
{
	int	i;
	int	width;
	int	current_width;

	i = 0;
	width = -1;
	while (map[i])
	{
		current_width = 0;
		while (map[i][current_width] && map[i][current_width] != '\n')
			current_width++;
		if (width == -1)
			width = current_width;
		else if (current_width != width)
			error_and_exit("El mapa no es rectangular.");
		i++;
	}
}

void	check_characters(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (map->copy[i])
	{
		j = 0;
		while (map->copy[i][j] && map->copy[i][j] != '\n')
		{
			if (map->copy[i][j] == '0')
				map->f++;
			else if (map->copy[i][j] == '1')
				map->w++;
			else if (map->copy[i][j] == 'E')
				map->e++;
			else if (map->copy[i][j] == 'C')
				map->c++;
			else if (map->copy[i][j] == 'P')
				map->p++;
			else
				error_and_exit("Carácter inválido");
			j++;
		}
		i ++;
	}
}

void	check_boundaries(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->num_columns)
	{
		if (map->copy[0][j] != '1' || map->copy[map->num_lines - 1][j] != '1')
			error_and_exit("El mapa no está cerrado.");
		j ++;
	}
	i = 0;
	while (i < map->num_lines - 1)
	{
		if (map->copy[i][0] != '1' || map->copy[i][map->num_columns - 1] != '1')
			error_and_exit("El mapa no está cerrado en los laterales.");
		i ++;
	}
}

void	validate_characters(t_map *map)
{
	if (map->p != 1)
		error_and_exit("El mapa debe contener exactamente 1 posición inicial.");
	if (map->e < 1)
		error_and_exit("El mapa debe contener al menos 1 salida (E).");
	if (map->c < 1)
		error_and_exit("El mapa debe contener al menos 1 coleccionable (C).");
}

void	validate_map(t_map *map)
{
	check_rectangular(map->copy);
	check_characters(map);
	validate_characters(map);
	count_cols(map);
	check_boundaries(map);
	player_position(map);
}
