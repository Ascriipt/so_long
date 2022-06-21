/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:34:52 by maparigi          #+#    #+#             */
/*   Updated: 2022/06/21 18:28:56 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	my_init(t_window *win, t_data *img, t_coord map)
{
	if (!img)
		return ;
	win->mlx = mlx_init();
	win->window = mlx_new_window(win->mlx, ((map.x - 1) * 64),
			((map.y - 1) * 64), "so_long");
	gen_map(map, win);
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
	t_window	win;
	t_data		img;

	if (ac < 2)
		return (1);
	map.map = parse_map(av[1]);
	map_main(&map);
	printtab(map.map);
	my_init(&win, &img, map);
	return (0);
}
