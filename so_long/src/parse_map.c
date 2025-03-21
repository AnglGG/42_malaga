/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:54:11 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/21 01:26:43 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_rectangular(char **map, t_game *game)
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
			error_and_exit("El mapa no es rectangular.", game);
		i++;
	}
}

void	check_characters(t_map *map, t_game *game)
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
				error_and_exit("Carácter inválido", game);
			j++;
		}
		i ++;
	}
}

void	check_boundaries(t_map *map, t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->num_columns)
	{
		if (map->copy[0][j] != '1' || map->copy[map->num_lines - 1][j] != '1')
			error_and_exit("El mapa no está cerrado.", game);
		j ++;
	}
	i = 0;
	while (i < map->num_lines - 1)
	{
		if (map->copy[i][0] != '1' || map->copy[i][map->num_columns - 1] != '1')
			error_and_exit("El mapa no está cerrado en los laterales.", game);
		i ++;
	}
}

void	validate_characters(t_map *map, t_game *game)
{
	if (map->p != 1)
		error_and_exit("El mapa debe contener exactamente 1 posición inicial.",
			game);
	if (map->e < 1)
		error_and_exit("El mapa debe contener al menos 1 salida (E).", game);
	if (map->c < 1)
		error_and_exit("El mapa debe contener al menos 1 coleccionable (C).",
			game);
}

void	validate_map(t_map *map, t_game *game)
{
	check_rectangular(map->copy, game);
	check_characters(map, game);
	validate_characters(map, game);
	count_cols(map);
	check_boundaries(map, game);
	player_position(map);
}
