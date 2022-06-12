/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:34:52 by maparigi          #+#    #+#             */
/*   Updated: 2022/06/12 12:54:17 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

//void	my_init(void *mlx, void *mlx_win, t_data img)
//{
//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
//	img.img = mlx_new_image(mlx, 1920, 1080);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//								&img.endian);
//}

//	int			height;
//	int			width;
//	void		*prout;
//	t_window	*win;

//	win->mlx = NULL;
//	win->window = NULL;
//	my_mlx_init(*win);
//	prout = mlx_xpm_file_to_image(win->mlx, "so_long_sprites/attack.xpm", &width, &height);
//	mlx_put_image_to_window(win->mlx, win->window, prout, 0, 0);
//	mlx_destroy_image(win->mlx, prout);
//	mlx_destroy_window(win->mlx, win->window);
//	mlx_destroy_display(win->mlx);
//	free(win->mlx);
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
	int	i = -1;
	
	while (tab[++i])
		printf("%s", tab[i]);
	return ;
}

int	main(int ac, char **av)
{
	t_coord	map;

	if (ac < 2)
		return (1);
	map.map = parse_map(av[1]);
	map_main(map);
	printtab(map.map);
	free_tab(map.map);
	return (0);
}
