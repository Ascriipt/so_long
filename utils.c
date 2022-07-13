/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:50:38 by maparigi          #+#    #+#             */
/*   Updated: 2022/07/13 12:56:14 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

int	ft_sizeof(int n, int ln)
{
	if (n == -2147483648)
		n = -2147483647;
	if (n < 0)
	{
		n = -n;
		return (1 + ft_sizeof(n, ln));
	}
	if (n < ln)
		return (1);
	return (1 + ft_sizeof(n / ln, ln));
}

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