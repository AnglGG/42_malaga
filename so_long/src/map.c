/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:51:50 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/12 14:02:16 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_lines(const char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	count = 0;
	if (fd < 0)
		error_and_exit("No se pudo abrir el archivo para contar líneas.");
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	count_cols(t_map *map)
{
	while (map[0][map->num_cols] && map[0][map->num_cols] != '\n')
		map->num_cols++;
}

char	**read_map(char *filename, int *num_lines)
{
	int		total_lines;
	char	**map;
	int		fd;
	int		i;
	char	*line;

	total_lines = count_lines(filename);
	*num_lines = total_lines;
	map = malloc((total_lines + 1) * sizeof(char *));
	if (!map)
		error_and_exit("Error de asignación de memoria para el mapa.");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_and_exit("No se pudo abrir el archivo del mapa.");
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	inicialize_map(t_map *map, char *filename)
{
	map->move_count = 0;
	map->num_cols = 0;
	map->num_lines = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
	map->f = 0;
	map->w = 0;
	map->copy = read_map(filename, map->num_lines);
}
