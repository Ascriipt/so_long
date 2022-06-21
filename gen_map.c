/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:45:48 by maparigi          #+#    #+#             */
/*   Updated: 2022/06/21 18:29:04 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	gen_map(t_coord map, t_window *win)
{
	int		i;
	int		j;
	int		xy[2];
	int		hw[2];
	void	*image;

	i = -1;
	xy[0] = 0;
	xy[1] = 0;
	while (map.map[++i])
	{
		j = -1;
		while (map.map[i][++j] && j < map.x)
		{
			image = mlx_xpm_file_to_image(win->mlx,
					"so_long_sprites/rsz_magueule.xpm", &hw[0], &hw[1]);
			if (!image)
				pexit_failfree("no image of this name exists.\n", map.map);
			mlx_put_image_to_window(win->mlx, win->window, image, xy[0], xy[1]);
			xy[0] += 64;
		}
		xy[0] = 0;
		xy[1] += 64;
	}
}
