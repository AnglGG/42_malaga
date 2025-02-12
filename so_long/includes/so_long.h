/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:00:38 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/12 12:38:30 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define UP      119
# define DOWN    115
# define LEFT    97
# define RIGHT   100

/* ==================== */
/* Inclusiones de sistema */
/* ==================== */
# include <stdlib.h>      // malloc, free, exit, EXIT_FAILURE
# include <unistd.h>      // close, read, etc.
# include <fcntl.h>       // open, O_RDONLY, etc.
# include <stdio.h>       // printf (si lo necesitas)
# include <stddef.h>      // NULL
# include <X11/keysym.h>  // Key symbols

/* ==================== */
/* Inclusiones de MiniLibX y libft */
/* ==================== */
# include "../minilibx-linux/mlx.h"  // Ajusta la ruta según tu estructura
# include "../libft/libft.h"         // Para ft_printf, get_next_line, etc.

/* ==================== */
/* Estructuras y declaraciones para renderizado */
/* ==================== */

typedef struct s_images
{
    void    *wall;
    void    *floor;
    void    *player;
    void    *exit;
    void    *collectible;
    int     width;
    int     height;
}   t_images;

/* Prototipos de funciones de renderizado */
void    load_images(void *mlx_ptr, t_images *imgs);
void    render_map(void *mlx_ptr, void *win_ptr, char **map, t_images *imgs);

/* ==================== */
/* Funciones de manejo del mapa */
/* ==================== */

/* Imprime un mensaje de error y finaliza el programa */
void    error_and_exit(const char *msg);

/* Cuenta el número de líneas del archivo de mapa */
int     count_lines(const char *filename);

/* Lee el mapa desde el archivo y devuelve un array de cadenas.
   El número de líneas se guarda en *num_lines */
char    **read_map(const char *filename, int *num_lines);

/* Verifica si el mapa es rectangular.
   Devuelve 1 si es rectangular, 0 en caso contrario */
int     check_rectangular(char **map);

/* Recorre el mapa y cuenta los caracteres especiales.
   Los contadores se guardan en el array 'characters' (índices:
   0: '0', 1: '1', 2: 'E', 3: 'C', 4: 'P') */
void    validate_characters(char **map, int *characters);

/* Comprueba que el mapa esté cerrado por paredes */
void    check_boundaries(char **map, int num_lines);

/* Realiza todas las validaciones del mapa:
   - Rectangularidad
   - Carácter válidos y cantidad mínima/máxima de elementos
   - Límites cerrados por paredes */
void    validate_map(char **map, int num_lines);

/* ==================== */
/* Estructura y funciones para eventos y datos del juego */
/* ==================== */

/* Estructura que contiene todos los datos del juego */
typedef struct s_game
{
    void    *mlx_ptr;
    void    *win_ptr;
    char    **map;
    t_images imgs;
    int     player_x;
    int     player_y;
    int     move_count;
}   t_game;

/* Prototipo de la función que manejará los eventos de teclado */
int     handle_key(int keysym, t_game *game);

#endif
