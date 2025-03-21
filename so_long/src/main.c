/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:58:45 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/20 23:53:04 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Uso: %s <archivo_del_mapa.ber>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	inicialize_map(&game.map, argv[1], &game);
	validate_map(&game.map, &game);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		error_and_exit("Error al inicializar MLX.", &game);
	load_images(game.mlx_ptr, &game.imgs, &game);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.map.num_columns * IMG_PXL,
			game.map.num_lines * IMG_PXL, "so_long");
	if (!game.win_ptr)
		error_and_exit("Error al crear la ventana.", &game);
	render_map(&game, &game.map, &game.imgs);
	mlx_key_hook(game.win_ptr, handle_key, &game);
	mlx_hook(game.win_ptr, 17, 0, close_window, &game);
	mlx_loop(game.mlx_ptr);
	free_game(&game);
	mlx_destroy_window(game.mlx_ptr, game.win_ptr);
	mlx_destroy_display(game.mlx_ptr);
	free(game.mlx_ptr);
}
