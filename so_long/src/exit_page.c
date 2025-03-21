/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:36:01 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/21 12:04:01 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_exit(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		free_game(game);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		exit(0);
	}
	return (0);
}

int	close_window(t_game *game)
{
	free_game(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}

void	ft_win(t_game *game)
{
	game->map.move_count++;
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		game->map.num_columns / 2 * IMG_PXL, game->map.num_lines / 2 * IMG_PXL,
		0xFFFA9E, "YOU WON");
	write(1, "\n", 1);
	write(1, "\x1b[32;01m", 9);
	write(1, "🏆🏆YOU WON!!🏆🏆\n", 27);
	write(1, "\x1b[0m", 5);
	close_window(game);
}
