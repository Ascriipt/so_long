/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:34:52 by maparigi          #+#    #+#             */
/*   Updated: 2022/07/12 16:48:25 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

int	event_manager(int keycode, t_gdata *sl)
{
	if (keycode == 17)
		close_game(sl);
	return (0);
}

void	my_init(t_gdata *sl)
{
	sl->win.mlx = mlx_init();
	if (!sl->win.mlx)
		pexit_failfree("mlx pointer init error\n", sl->map.map);
	sl->win.window = mlx_new_window(sl->win.mlx, ((sl->map.x) * 64),
			((sl->map.y) * 64), "so_long");
	init_texture(&(sl->game_t), &(sl->win));
	gen_map(sl->map, &(sl->win), sl->game_t);
	mlx_hook(sl->win.mlx, 17, 0, event_manager, sl);
	mlx_loop(sl->win.mlx);
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
	t_gdata	so_long;

	if (ac != 2)
		return (1);
	so_long.map.map = parse_map(av[1]);
	map_main(&(so_long.map));
	printtab(so_long.map.map);
	my_init(&so_long);
	return (0);
}
