/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_lib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:26:48 by maparigi          #+#    #+#             */
/*   Updated: 2022/07/13 02:38:36 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_LIB_H
# define SO_LONG_LIB_H

# include <mlx.h>
# include <mlx_int.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>

# include <libft.h>
# include <get_next_line.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_textures
{
	void	*walls;
	void	*player_r;
	void	*player_l;
	void	*floor;
	void	*ennemy_r;
	void	*ennemy_l;
	void	*collectibles;
}				t_texture;

typedef struct s_window
{
	void	*mlx;
	void	*window;
}				t_window;

typedef struct s_coord
{
	char			**map;
	int				x;
	int				y;
	int				px;
	int				py;
}				t_coord;

typedef struct s_gdata
{
	t_data		img;
	t_coord		map;
	t_window	win;
	t_texture	game_t;
}				t_gdata;

void	free_texturexmap(t_texture *game_t, t_window *win, t_coord *map);
void	my_pixel_put(t_data *data, int x, int y, int color);
void	find_player(int *px, int *py, char **map);
void	my_mlx_init(t_window *window);
void	init_texture(t_gdata *sl);

/*------------parse------------*/

char	**parse_map(char *av);

/*------------check------------*/

void	map_main(t_coord *map);

/*--------map_generation-------*/

void	gen_map(t_coord map, t_window *win, t_texture game_t);

/*-------------exit-------------*/

void	free_tab(char **tab);
void	close_game(t_gdata *sl);
void	pexit_failure(char *str);
void	pexit_failfree(char *str, char **map);

#endif