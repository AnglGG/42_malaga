/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:00:38 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/12 14:12:20 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define UP      119
# define DOWN    115
# define LEFT    97
# define RIGHT   100

/* ====================== */
/* Inclusiones de sistema */
/* ====================== */

# include <stdlib.h>      // malloc, free, exit, EXIT_FAILURE
# include <unistd.h>      // close, read, etc.
# include <fcntl.h>       // open, O_RDONLY, etc.
# include <stdio.h>       // printf (si lo necesitas)
# include <stddef.h>      // NULL
# include <X11/keysym.h>  // Key symbols

/* =============================== */
/* Inclusiones de MiniLibX y libft */
/* =============================== */
# include "../minilibx-linux/mlx.h"  // Ajusta la ruta según tu estructura
# include "../libft/libft.h"         // Para ft_printf, get_next_line, etc.

/* ==================== */
/* Estructuras			*/
/* ==================== */

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_images	imgs;
}	t_game;

typedef struct s_map
{
	char	**copy_map;
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
	int		width;
	int		height;
}	t_images;

/* ==================== */
/* map.c				*/
/* ==================== */

void	inicialize_map(t_map *map, char *filename);
char	**read_map(char *filename, int *num_lines);
void	count_cols(t_map *map);
int		count_lines(const char *filename);

/* ==================== */
/* parse_map.c			*/
/* ==================== */

void	validate_map(t_map *map);
void	validate_characters(t_map *map);
void	check_boundaries(t_map map);
void	check_characters(t_map *map);
void	check_rectangular(char **map);

#endif
