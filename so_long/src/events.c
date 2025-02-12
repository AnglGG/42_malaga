/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:03:33 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/10 19:37:10 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_collectibles(char **map)
{
	int i;
	int j;
	int count;

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
	if (game->map[new_y][new_x] == 'E')
	{
		if (count_collectibles(game->map) == 0)
		{
			ft_printf("¡Has ganado en %d movimientos!\n", game->move_count);
			/* Aquí podrías, en lugar de simplemente cerrar la ventana,
			   mostrar una pantalla de victoria si así lo deseas */
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
			exit(0);
		}
		else
		{
			ft_printf("¡Aún quedan coleccionables!\n");
			return (0);
		}
	}
	return(1);
}

int	handle_key(int keysym, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keysym == DOWN)
		new_y++;
	else if (keysym == UP)
		new_y--;
	else if (keysym == LEFT)
		new_x--;
	else if (keysym == RIGHT)
		new_x++;
	else if (keysym == XK_Escape)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		exit(0);
	}
	if (!check_exit(game, new_x, new_y))
		return (0);
	if (game->map[new_y][new_x] != '1')
	{
		game->move_count++;
		ft_printf("Movimientos: %d\n", game->move_count);
		game->map[game->player_y][game->player_x] = '0';
		game->map[new_y][new_x] = 'P';
		game->player_y = new_y;
		game->player_x = new_x;
		render_map(game->mlx_ptr, game->win_ptr, game->map, &game->imgs);
	}
	return (0);
}
