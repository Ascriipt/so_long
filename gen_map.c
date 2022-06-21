/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:45:48 by maparigi          #+#    #+#             */
/*   Updated: 2022/06/21 13:00:35 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	gen_map(t_coord map, t_window *win)
{
	int		i;
	int		j;
	int		xx;
	int		yy;
	void	*image;
	int		xp;
	int		yp;

	i = -1;
	xx = 0;
	yy = 0;
	while (map.map[++i])
	{
		j = -1;
		while (map.map[i][++j] && j < map.x)
		{
			image = mlx_xpm_file_to_image(win->mlx, "so_long_sprites/attack-2.xpm", &xp, &yp);
			mlx_put_image_to_window(win->mlx, win->window, image, xx, yy);
			xx += 64;
		}
		xx = 0;
		yy += 64;
	}
}