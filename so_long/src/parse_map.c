/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:54:11 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/24 17:59:35 by anggalle         ###   ########.fr       */
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
			error_and_exit("the map is not rectangular.", game);
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
				error_and_exit("invalid character", game);
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
			error_and_exit("the map is not closed", game);
		j ++;
	}
	i = 0;
	while (i < map->num_lines - 1)
	{
		if (map->copy[i][0] != '1' || map->copy[i][map->num_columns - 1] != '1')
			error_and_exit("the map is not closed in the sides.", game);
		i ++;
	}
}

void	validate_characters(t_map *map, t_game *game)
{
	if (map->p != 1)
		error_and_exit("the map must contain 1 initial position (P).",
			game);
	if (map->e != 1)
		error_and_exit("the map must contain one exit (E).", game);
	if (map->c < 1)
		error_and_exit("the mup must conatin at least one collectible (C).",
			game);
}

void	validate_map(t_map *map, t_game *game, char *filename)
{
	check_rectangular(map->copy, game);
	check_characters(map, game);
	validate_characters(map, game);
	count_cols(map);
	check_boundaries(map, game);
	player_position(map);
	check_path_validity(map, game, filename);
}
