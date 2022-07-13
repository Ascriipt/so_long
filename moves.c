/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:30:14 by maparigi          #+#    #+#             */
/*   Updated: 2022/07/13 02:48:47 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	find_player(int *px, int *py, char **map)
{
	int	i;
	int	j;
	
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				*px = j;
				*py = i;
			}
		}
	}
}

//void	move_up()
//{
//}

//void	move_down()
//{
//}

//void	move_left()
//{
//}

//void	move_right()
//{
//}