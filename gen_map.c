/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:45:48 by maparigi          #+#    #+#             */
/*   Updated: 2022/07/12 17:20:48 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	init_texture(t_texture *game_t, t_window *win)
{
	int		hw[2];

	game_t->collectibles = mlx_xpm_file_to_image(win->mlx,
			"so_long_sprites/dolla.xpm", &hw[0], &hw[1]);
	game_t->ennemy_l = mlx_xpm_file_to_image(win->mlx,
			"so_long_sprites/ennemy_l.xpm", &hw[0], &hw[1]);
	game_t->ennemy_r = mlx_xpm_file_to_image(win->mlx,
			"so_long_sprites/ennemy_r.xpm", &hw[0], &hw[1]);
	game_t->player_r = mlx_xpm_file_to_image(win->mlx,
			"so_long_sprites/Sprite_1.1.xpm", &hw[0], &hw[1]);
	game_t->player_l = mlx_xpm_file_to_image(win->mlx,
			"so_long_sprites/Sprite_1.xpm", &hw[0], &hw[1]);
	game_t->walls = mlx_xpm_file_to_image(win->mlx,
			"so_long_sprites/Wall.xpm", &hw[0], &hw[1]);
	game_t->floor = mlx_xpm_file_to_image(win->mlx,
			"so_long_sprites/floor.xpm", &hw[0], &hw[1]);
}

void	close_game(t_gdata *sl)
{
	if (sl->map.map)
		free_tab(sl->map.map);
	if (sl->game_t.collectibles)
		mlx_destroy_image(sl->win.mlx, sl->game_t.collectibles);
	if (sl->game_t.player_l)
		mlx_destroy_image(sl->win.mlx, sl->game_t.player_l);
	if (sl->game_t.player_r)
		mlx_destroy_image(sl->win.mlx, sl->game_t.player_r);
	if (sl->game_t.ennemy_l)
		mlx_destroy_image(sl->win.mlx, sl->game_t.ennemy_l);
	if (sl->game_t.ennemy_r)
		mlx_destroy_image(sl->win.mlx, sl->game_t.ennemy_r);
	if (sl->game_t.walls)
		mlx_destroy_image(sl->win.mlx, sl->game_t.walls);
	if (sl->game_t.floor)
		mlx_destroy_image(sl->win.mlx, sl->game_t.floor);
	if (sl->win.mlx)
	{
		mlx_destroy_window(sl->win.mlx, sl->win.window);
		mlx_destroy_display(sl->win.mlx);
		mlx_loop_end(sl->win.mlx);
		free(sl->win.mlx);
	}
	exit(EXIT_SUCCESS);
}

static void	match_to_map(char c, int xy[2], t_window *win, t_texture game_t)
{
	if (c == '1')
		mlx_put_image_to_window(win->mlx, win->window,
			game_t.walls, xy[0], xy[1]);
	else if (c == '0')
		mlx_put_image_to_window(win->mlx, win->window,
			game_t.floor, xy[0], xy[1]);
	else if (c == 'P')
		mlx_put_image_to_window(win->mlx, win->window,
			game_t.player_r, xy[0], xy[1]);
	else if (c == 'E')
		mlx_put_image_to_window(win->mlx, win->window,
			game_t.ennemy_r, xy[0], xy[1]);
	else if (c == 'C')
		mlx_put_image_to_window(win->mlx, win->window,
			game_t.collectibles, xy[0], xy[1]);
}

void	gen_map(t_coord map, t_window *win, t_texture game_t)
{
	int		i;
	int		j;
	int		xy[2];

	i = -1;
	xy[0] = 0;
	xy[1] = 0;
	while (map.map[++i])
	{
		j = -1;
		while (map.map[i][++j] && j < map.x)
		{
			match_to_map(map.map[i][j], xy, win, game_t);
			xy[0] += 64;
		}
		xy[0] = 0;
		xy[1] += 64;
	}
}
