/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:58:45 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/12 13:57:49 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
	return (0);
}

inicialize_image(t_image *img)
{
	imgs->width = 32;
	imgs->height = 32;
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;
	int		j;

	if (argc != 2)
	{
		ft_printf("Uso: %s <archivo_del_mapa.ber>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	inicialize_map(&game.map, argv[1]);
	validate_map(&game.map);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		error_and_exit("Error al inicializar MLX.");
	load_images(game.mlx_ptr, &game.imgs);
	game.win_ptr = mlx_new_window(game.mlx_ptr, num_cols * game.imgs.width,
			num_lines * game.imgs.height, "so_long");
	if (!game.win_ptr)
		error_and_exit("Error al crear la ventana.");
	for (i = 0; game.map[i]; i++)
	{
		for (j = 0; game.map[i][j] && game.map[i][j] != '\n'; j++)
		{
			if (game.map[i][j] == 'P')
			{
				game.player_y = i;
				game.player_x = j;
				break;
			}
		}
	}

	/* Renderizar el mapa inicial */
	render_map(game.mlx_ptr, game.win_ptr, game.map, &game.imgs);

	/* Hook para el teclado: cada vez que se pulse una tecla se llamará a handle_key */
	mlx_key_hook(game.win_ptr, handle_key, &game);
	mlx_hook(game.win_ptr, 17, 0, close_window, &game);

	/* Bucle de MLX */
	mlx_loop(game.mlx_ptr);

	/* Liberar recursos (si implementas una función de liberación) */
	i = 0;
	while (game.map[i])
		free(game.map[i++]);
	free(game.map);

	return (EXIT_SUCCESS);
}
