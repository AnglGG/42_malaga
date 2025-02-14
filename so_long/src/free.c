/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:14:43 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/14 13:42:40 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.copy[i])
	{
		free(game->map.copy[i]);
		i++;
	}
	free(game->map.copy);
	if (game->imgs.wall)
		mlx_destroy_image(game->mlx_ptr, game->imgs.wall);
	if (game->imgs.floor)
		mlx_destroy_image(game->mlx_ptr, game->imgs.floor);
	if (game->imgs.player)
		mlx_destroy_image(game->mlx_ptr, game->imgs.player);
	if (game->imgs.exit)
		mlx_destroy_image(game->mlx_ptr, game->imgs.exit);
	if (game->imgs.collectible)
		mlx_destroy_image(game->mlx_ptr, game->imgs.collectible);
	// mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	// mlx_destroy_display(game->mlx_ptr);
	// free(game->mlx_ptr);
}

