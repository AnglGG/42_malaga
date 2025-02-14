/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:00:38 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/14 14:32:04 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define UP      119
# define DOWN    115
# define LEFT    97
# define RIGHT   100
# define IMG_PXL 50

/* ====================== */
/* Inclusiones de sistema */
/* ====================== */

# include <stdlib.h>      // malloc, free, exit, EXIT_FAILURE
# include <unistd.h>      // close, read, etc.
# include <fcntl.h>       // open, O_RDONLY, etc.
# include <stdio.h>       // printf (si lo necesitas)
# include <stddef.h>      // NULL
# include <X11/keysym.h>  // Key symbols
# include <signal.h>

/* =============================== */
/* Inclusiones de MiniLibX y libft */
/* =============================== */
# include "../minilibx-linux/mlx.h"  // Ajusta la ruta según tu estructura
# include "../libft/libft.h"         // Para ft_printf, get_next_line, etc.

/* ==================== */
/* Estructuras			*/
/* ==================== */

typedef struct s_map
{
	char	**copy;
	int		player_x;
	int		player_y;
	int		move_count;
	int		num_lines;
	int		num_columns;
	int		e;
	int		c;
	int		p;
	int		f;
	int		w;
}	t_map;

typedef struct s_images
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collectible;
}	t_images;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_images	imgs;
}	t_game;

/* ==================== */
/* map.c				*/
/* ==================== */

void	inicialize_map(t_map *map, char *filename);
char	**read_map(char *filename, int *num_lines);
void	count_cols(t_map *map);
int		count_lines(const char *filename);
void	player_position(t_map *map);

/* ==================== */
/* parse_map.c			*/
/* ==================== */

void	validate_map(t_map *map);
void	validate_characters(t_map *map);
void	check_boundaries(t_map *map);
void	check_characters(t_map *map);
void	check_rectangular(char **map);

/* ==================== */
/* render.c				*/
/* ==================== */

void	load_images(void *mlx_ptr, t_images *imgs);
void	print_map_type(t_game *game, t_images *imgs, int x, int y);
void	render_map(t_game *game, t_map *map, t_images *imgs);


/* ==================== */
/* free.c				*/
/* ==================== */
void	free_game(t_game *game);

/* ==================== */
/* events.c				*/
/* ==================== */
int	handle_key(int keysym, t_game *game);


/* ==================== */
/* exit_page.c			*/
/* ==================== */
int		close_window(t_game *game);
void	ft_win(t_game *game);

/* ==================== */
/* errors.c				*/
/* ==================== */
void	error_and_exit(const char *msg);

#endif
