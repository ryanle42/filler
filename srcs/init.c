/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 18:14:01 by rle               #+#    #+#             */
/*   Updated: 2017/04/18 20:20:41 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_dim(t_coord *coord, int j)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	if (j % 2 == 0 && ft_strncmp(line, "Plateau", 7))
	{
		ft_putstr_fd(line, 2);
		exit(0);
	}
	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	while (ft_isdigit(line[i]))
	{
		coord->y *= 10;
		coord->y += line[i] - '0';
		i++;
	}
	i++;
	while (ft_isdigit(line[i]))
	{
		coord->x *= 10;
		coord->x += line[i] - '0';
		i++;
	}
}

t_player	get_player(void)
{
	t_player	player;
	char		*line;

	get_next_line(0, &line);
	if (ft_strstr(line, "p1"))
	{
		player.you = 'o';
		player.opp = 'x';
	}
	else
	{
		player.you = 'x';
		player.opp = 'o';
	}
	return (player);
}

void		zero_coord(t_coord *coord)
{
	(*coord).x = 0;
	(*coord).y = 0;
}

t_dist		init_dist(t_player player)
{
	t_dist	dist;

	dist.player = player;
	dist.best = 10000;
	return (dist);
}

t_dim		make_dim(void)
{
	t_dim	dim;

	dim.map.x = 0;
	dim.map.y = 0;
	dim.piece.x = 0;
	dim.piece.y = 0;
	dim.ans.x = 0;
	dim.ans.y = 0;
	return (dim);
}
