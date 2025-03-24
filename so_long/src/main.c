/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:58:45 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/24 17:59:57 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error: Incorrect number of arguments\n", argv[0]);
		return (EXIT_FAILURE);
	}
	inicialize_map(&game.map, argv[1], &game);
	validate_map(&game.map, &game, argv[1]);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		error_and_exit("while inicializating MLX.", &game);
	load_images(game.mlx_ptr, &game.imgs, &game);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.map.num_columns * IMG_PXL,
			game.map.num_lines * IMG_PXL, "so_long");
	if (!game.win_ptr)
		error_and_exit("while creating the window.", &game);
	render_map(&game, &game.map);
	mlx_key_hook(game.win_ptr, handle_key, &game);
	mlx_hook(game.win_ptr, 17, 0, close_window, &game);
	mlx_loop(game.mlx_ptr);
	free_game(&game);
	mlx_destroy_window(game.mlx_ptr, game.win_ptr);
	mlx_destroy_display(game.mlx_ptr);
	free(game.mlx_ptr);
}
