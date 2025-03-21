/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:03:33 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/21 11:42:31 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_exit(t_game *game, int new_x, int new_y)
{
	if (game->map.copy[new_y][new_x] == 'E')
	{
		if (count_collectibles(game->map.copy) == 0)
		{
			ft_printf("¡Has ganado en %d movimientos!\n", game->map.move_count);
			ft_win(game);
		}
		else
		{
			ft_printf("¡Aún quedan coleccionables!\n");
			return (0);
		}
	}
	return (1);
}

void	compute_new_position(int keysym, int *new_x, int *new_y)
{
	if (keysym == DOWN)
		(*new_y)++;
	else if (keysym == UP)
		(*new_y)--;
	else if (keysym == LEFT)
		(*new_x)--;
	else if (keysym == RIGHT)
		(*new_x)++;
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	game->map.move_count++;
	ft_printf("Movimientos: %d\n", game->map.move_count);
	game->map.copy[game->map.player_y][game->map.player_x] = '0';
	game->map.copy[new_y][new_x] = 'P';
	game->map.player_y = new_y;
	game->map.player_x = new_x;
	render_map(game, &game->map, &game->imgs);
}

int	handle_key(int keysym, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->map.player_x;
	new_y = game->map.player_y;
	if (keysym == XK_Escape)
	{
		free_game(game);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		exit(0);
	}
	compute_new_position(keysym, &new_x, &new_y);
	if (!check_exit(game, new_x, new_y))
		return (0);
	if (game->map.copy[new_y][new_x] != '1')
		update_player_position(game, new_x, new_y);
	return (0);
}
