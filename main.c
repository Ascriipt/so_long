/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:34:52 by maparigi          #+#    #+#             */
/*   Updated: 2022/06/21 10:33:06 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	my_init(t_window *win, t_data *img, t_coord map)
{
	win->mlx = mlx_init();
	win->window = mlx_new_window(win->mlx, (map.x * 64), (map.y * 64), "Hello world!");
	img->img = mlx_new_image(win->mlx, (map.x * 64), (map.y * 64));
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
	mlx_loop(win->mlx);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	if (tab)
		free(tab);
}

void	printtab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		printf("%s", tab[i]);
	return ;
}

int	main(int ac, char **av)
{
	t_coord		map;
//	t_window	win;
//	t_data		img;

	if (ac < 2)
		return (1);
	map.map = parse_map(av[1]);
	map_main(&map);
	printtab(map.map);
	free_tab(map.map);
	//my_init(&win, &img, map);
	return (0);
}
