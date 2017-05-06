/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 19:05:02 by rle               #+#    #+#             */
/*   Updated: 2017/05/06 12:42:36 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_heat(char **heatmap, t_dim dim)
{
	int x;
	int y;

	y = 0;
	ft_putstr_fd("\n", 2);
	while (y < dim.map.y)
	{
		x = 0;
		while (x < dim.map.x)
		{
			if (heatmap[y][x] == 0)
				ft_putstr_fd(".", 2);
			else
				ft_putnbr_fd(heatmap[y][x], 2);
			x++;
		}
		ft_putstr_fd("\n", 2);
		y++;
	}
	ft_putstr_fd("\n", 2);
	usleep(100000);
}

char	**copy_map(char **map, t_dim dim)
{
	char	**heatmap;
	int		i;

	heatmap = (char **)malloc(sizeof(char *) * dim.map.y);
	i = 0;
	while (i < dim.map.y)
	{
		heatmap[i] = ft_copystr(map[i]);
		i++;
	}
	return (heatmap);
}

void	make_heat(char **map, t_dim dim, char level, float fade)
{
	int	x;
	int	y;
	int	thresh;

	if (level <= 1)
		return ;
	y = -1;
	while (++y < dim.map.y && (x = -1))
		while (++x < dim.map.x)
			if (map[y][x] > 0)
			{
				thresh = map[y][x];
				if (x + 1 < dim.map.x && map[y][x + 1] < thresh)
					map[y][x + 1] = thresh / fade;
				if (x - 1 > 0 && map[y][x - 1] < thresh)
					map[y][x - 1] = thresh / fade;
				if (y + 1 < dim.map.y && map[y + 1][x] < thresh)
					map[y + 1][x] = thresh / fade;
				if (y - 1 > 0 && map[y - 1][x] < thresh)
					map[y - 1][x] = thresh / fade;
			}
	make_heat(map, dim, level / fade, fade);
}

char	**prepare_heat(char **map, t_dim dim, t_player player)
{
	int	x;
	int	y;

	y = 0;
	while (y < dim.map.y)
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_tolower(map[y][x]) == player.opp)
				map[y][x] = 9;
			else
				map[y][x] = 0;
			x++;
		}
		y++;
	}
	return (map);
}
