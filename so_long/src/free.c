/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:14:43 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/21 13:07:39 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.copy)
	{
		while (game->map.copy[i])
		{
			free(game->map.copy[i]);
			i++;
		}
	}
	if (game->map.copy)
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
}
