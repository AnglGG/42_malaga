/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:54:29 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/24 17:51:36 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_images(void *mlx_ptr, t_images *imgs, t_game *game)
{
	int	img_pxl;

	img_pxl = IMG_PXL;
	imgs->wall = mlx_xpm_file_to_image(mlx_ptr, "images/water.xpm",
			&img_pxl, &img_pxl);
	if (!imgs->wall)
		error_and_exit("while loading the wall image (wall.xpm).", game);
	imgs->floor = mlx_xpm_file_to_image(mlx_ptr, "images/grass.xpm",
			&img_pxl, &img_pxl);
	if (!imgs->floor)
		error_and_exit("while loading the floor image (floor.xpm).", game);
	imgs->player = mlx_xpm_file_to_image(mlx_ptr, "images/cat.xpm",
			&img_pxl, &img_pxl);
	if (!imgs->player)
		error_and_exit("while loading the player image (cat.xpm).", game);
	imgs->exit = mlx_xpm_file_to_image(mlx_ptr, "images/exit.xpm",
			&img_pxl, &img_pxl);
	if (!imgs->exit)
		error_and_exit("while loading the exit image (exit.xpm).", game);
	imgs->collectible = mlx_xpm_file_to_image(mlx_ptr, "images/star.xpm",
			&img_pxl, &img_pxl);
	if (!imgs->collectible)
		error_and_exit("while loading the collectible image.", game);
}

void	print_map_type(t_game *game, t_images *imgs, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		imgs->floor, x, y);
	if (game->map.copy[y / IMG_PXL][x / IMG_PXL] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			imgs->wall, x, y);
	else if (game->map.copy[y / IMG_PXL][x / IMG_PXL] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			imgs->floor, x, y);
	else if (game->map.copy[y / IMG_PXL][x / IMG_PXL] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			imgs->player, x, y);
	else if (game->map.copy[y / IMG_PXL][x / IMG_PXL] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			imgs->exit, x, y);
	else if (game->map.copy[y / IMG_PXL][x / IMG_PXL] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			imgs->collectible, x, y);
}

void	render_map(t_game *game, t_map *map)
{
	int	row;
	int	col;
	int	x;
	int	y;

	row = 0;
	while (map->copy[row])
	{
		col = 0;
		while (map->copy[row][col] && map->copy[row][col] != '\n')
		{
			x = col * IMG_PXL;
			y = row * IMG_PXL;
			print_map_type(game, &game->imgs, x, y);
			col++;
		}
		row++;
	}
}
