/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:22:56 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/21 13:53:29 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	floodfill(t_map *map, int *found_exit, int *collected, t_game *game)
{
	if (map->player_x < 0 || map->player_y < 0
		|| map->player_y >= map->num_lines || map->player_x >= map->num_columns)
		return ;
	if (map->copy[map->player_y][map->player_x] == '1'
		|| map->copy[map->player_y][map->player_x] == 'V')
		return ;
	if (map->copy[map->player_y][map->player_x] == 'E')
	{
		*found_exit = 1;
		return ;
	}
	if (map->copy[map->player_y][map->player_x] == 'C')
		(*collected)++;
	map->copy[map->player_y][map->player_x] = 'V';
	map->player_x++;
	floodfill(map, found_exit, collected, game);
	map->player_x -= 2;
	floodfill(map, found_exit, collected, game);
	map->player_x++;
	map->player_y++;
	floodfill(map, found_exit, collected, game);
	map->player_y -= 2;
	floodfill(map, found_exit, collected, game);
	map->player_y++;
}

void	check_path_validity(t_map *map, t_game *game, char *filename)
{
	int	found_exit;
	int	collected;

	found_exit = 0;
	collected = 0;
	floodfill(map, &found_exit, &collected, game);
	if (!found_exit || collected != map->c)
	{
		error_and_exit("No se puede recoger todos los collecionables.", game);
	}
	free_matrix(game->map.copy);
	game->map.copy = read_map(filename, &game->map.num_lines, game);
}
