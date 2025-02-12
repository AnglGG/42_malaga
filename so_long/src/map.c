/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:51:50 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/10 18:14:24 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void error_and_exit(const char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}

int	count_lines(const char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	count = 0;
	if (fd < 0)
		error_and_exit("No se pudo abrir el archivo para contar líneas.");

	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		free(line);
	}
	close(fd);
	return count;
}

char	**read_map(const char *filename, int *num_lines)
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
	while ((line = get_next_line(fd)) != NULL)
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	check_rectangular(char **map)
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
			return (0);
		i++;
	}
	return (1);
}

void validate_characters(char **map, int *characters)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 5)
	{
		characters[i] = 0;
		i ++;
	}
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			c = map[i][j];
			if (c == '0')
				characters[0]++;
			else if (c == '1')
				characters[1]++;
			else if (c == 'E')
				characters[2]++;
			else if (c == 'C')
				characters[3]++;
			else if (c == 'P')
				characters[4]++;
			else
			{
				ft_printf("Error: Carácter inválido '%c' en línea %d, columna %d.\n", c, i + 1, j + 1);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void check_boundaries(char **map, int num_lines)
{
	int	i;
	int	j;
	int	width;

	width = 0;
	while (map[0][width] && map[0][width] != '\n')
		width++;
	j = 0;
	while (j < width)
	{
		if (map[0][j] != '1' || map[num_lines - 1][j] != '1')
			error_and_exit("El mapa no está cerrado en la parte superior/inferior.");
		j ++;
	}
	i = 1;
	while(i < num_lines - 1)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			error_and_exit("El mapa no está cerrado en los laterales.");
		i ++;
	}
}

void validate_map(char **map, int num_lines)
{
	int characters[5];

	if (!check_rectangular(map))
		error_and_exit("El mapa no es rectangular.");
	validate_characters(map, characters);
	if (characters[4] != 1)
		error_and_exit("El mapa debe contener exactamente 1 posición inicial (P).");
	if (characters[2] < 1)
		error_and_exit("El mapa debe contener al menos 1 salida (E).");
	if (characters[3] < 1)
		error_and_exit("El mapa debe contener al menos 1 coleccionable (C).");
	check_boundaries(map, num_lines);
}