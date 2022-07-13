/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:50:38 by maparigi          #+#    #+#             */
/*   Updated: 2022/07/13 04:02:05 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	mp_swop(char *x, char *y)
{
	char	swop;

	swop = *x;
	*x = *y;
	*y = swop; 
}

void	count_collectibles(int *t_col, char **map)
{
	int	i;
	int	j;

	i = -1;
	*t_col = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				*t_col += 1;
		}
	}
}