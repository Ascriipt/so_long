/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:45:48 by maparigi          #+#    #+#             */
/*   Updated: 2022/07/10 15:30:12 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	init_texture(t_texture *game_t, t_window *win)
{
	int		hw[2];

	game_t->collectibles = mlx_xpm_file_to_image(win->mlx,
			"so_long_sprites/rsz_magueule.xpm", &hw[0], &hw[1]);
	game_t->ennemy = mlx_xpm_file_to_image(win->mlx,
			"so_long_sprites/rsz_magueule.xpm", &hw[0], &hw[1]);
	game_t->player = mlx_xpm_file_to_image(win->mlx,
			"so_long_sprites/rsz_magueule.xpm", &hw[0], &hw[1]);
	game_t->walls = mlx_xpm_file_to_image(win->mlx,
			"so_long_sprites/rsz_magueule.xpm", &hw[0], &hw[1]);
	game_t->floor = mlx_xpm_file_to_image(win->mlx,
			"so_long_sprites/rsz_magueule.xpm", &hw[0], &hw[1]);
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
			mlx_put_image_to_window(win->mlx, win->window,
				game_t.collectibles, xy[0], xy[1]);
			xy[0] += 64;
		}
		xy[0] = 0;
		xy[1] += 64;
	}
}
