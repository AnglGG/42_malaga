/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:54:29 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/11 19:11:07 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void load_images(void *mlx_ptr, t_images *imgs)
{
	imgs->wall = mlx_xpm_file_to_image(mlx_ptr, "images/wall.xpm", &imgs->width, &imgs->height);
	if (!imgs->wall)
		error_and_exit("Error al cargar la imagen de pared (wall.xpm).");
	imgs->floor = mlx_xpm_file_to_image(mlx_ptr, "images/floor.xpm", &imgs->width, &imgs->height);
	if (!imgs->floor)
		error_and_exit("Error al cargar la imagen del piso (floor.xpm).");
	imgs->player = mlx_xpm_file_to_image(mlx_ptr, "images/cat.xpm", &imgs->width, &imgs->height);
	if (!imgs->player)
		error_and_exit("Error al cargar la imagen del jugador (cat.xpm).");
	imgs->exit = mlx_xpm_file_to_image(mlx_ptr, "images/exit.xpm", &imgs->width, &imgs->height);
	if (!imgs->exit)
		error_and_exit("Error al cargar la imagen de salida (exit.xpm).");
	imgs->collectible = mlx_xpm_file_to_image(mlx_ptr, "images/star.xpm", &imgs->width, &imgs->height);
	if (!imgs->collectible)
		error_and_exit("Error al cargar la imagen de coleccionable (collectible.xpm).");
}

void render_map(void *mlx_ptr, void *win_ptr, char **map, t_images *imgs)
{
	int row;
	int col;
	int x;
	int y;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col] && map[row][col] != '\n')
		{
			x = col * imgs->width;
			y = row * imgs->height;

			mlx_put_image_to_window(mlx_ptr, win_ptr, imgs->floor, x, y);
			if (map[row][col] == '1')
				mlx_put_image_to_window(mlx_ptr, win_ptr, imgs->wall, x, y);
			else if (map[row][col] == '0')
				mlx_put_image_to_window(mlx_ptr, win_ptr, imgs->floor, x, y);
			else if (map[row][col] == 'P')
				mlx_put_image_to_window(mlx_ptr, win_ptr, imgs->player, x, y);
			else if (map[row][col] == 'E')
				mlx_put_image_to_window(mlx_ptr, win_ptr, imgs->exit, x, y);
			else if (map[row][col] == 'C')
				mlx_put_image_to_window(mlx_ptr, win_ptr, imgs->collectible, x, y);
			col++;
		}
		row++;
	}
}
