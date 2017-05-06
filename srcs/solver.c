/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 19:00:12 by rle               #+#    #+#             */
/*   Updated: 2017/05/05 13:34:36 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coord		opp_pos(char **map, t_dim dim, t_player player)
{
	t_coord	pos;

	pos.y = 0;
	while (pos.y < dim.map.y)
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (ft_tolower(map[pos.y][pos.x]) == player.opp)
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	return (pos);
}

int			is_safe(t_data data, t_dim dim, t_player player, t_coord pos)
{
	int	i;
	int	j;
	int	ontop;

	i = -1;
	ontop = 0;
	while (++i + dim.shift.y < dim.piece.y && (j = -1))
		while (data.piece[i + dim.shift.y][++j + dim.shift.x])
		{
			if (data.piece[i + dim.shift.y][j + dim.shift.x] == '*' && \
					(pos.y + i >= dim.map.y || pos.x + j >= dim.map.x))
				return (0);
			if (data.piece[i + dim.shift.y][j + dim.shift.x] == '*' && \
					ft_tolower(data.map[pos.y + i][pos.x + j]) == player.you)
				ontop++;
			if ((data.piece[i + dim.shift.y][j + dim.shift.x] == '*') && \
				(ft_tolower(data.map[pos.y + i][pos.x + j]) == player.opp \
				|| ontop > 1))
				return (0);
		}
	return (ontop);
}

int			get_points(t_data data, t_dim dim, t_coord pos, t_dist *dist)
{
	int	points;
	int	i;
	int	j;

	i = 0;
	points = 0;
	while (i + dim.shift.y < dim.piece.y)
	{
		j = 0;
		while (data.piece[i + dim.shift.y][j + dim.shift.x])
		{
			if (data.piece[i + dim.shift.y][j + dim.shift.x] == '*')
				points += data.heatmap[pos.y + i][pos.x + j];
			j++;
		}
		i++;
	}
	(*dist).tmp = dist_form(pos, opp_pos(data.map, dim, (*dist).player));
	if ((*dist).best > (*dist).tmp)
	{
		(*dist).best = (*dist).tmp;
		(*dist).pos = pos;
	}
	return (points);
}

t_coord		place_piece(t_data data, t_dim dim, t_player player)
{
	int		best;
	int		tmp;
	t_coord	pos;
	t_coord	best_coord;
	t_dist	dist;

	zero_coord(&best_coord);
	dist = init_dist(player);
	pos.y = -1;
	best = -1;
	while (++pos.y < dim.map.y && (pos.x = -1))
		while (data.map[pos.y][++pos.x])
			if (is_safe(data, dim, player, pos))
			{
				tmp = get_points(data, dim, pos, &dist);
				if (tmp > best)
				{
					best = tmp;
					best_coord = pos;
				}
			}
	if (!best)
		return (dist.pos);
	return (best_coord);
}

char		*convert_ans(t_coord pos, t_coord shift)
{
	char	*ans;

	ans = ft_strjoin(ft_itoa(pos.y - shift.y), " ");
	ans = ft_strjoin(ans, ft_itoa(pos.x - shift.x));
	ans = ft_strjoin(ans, "\n");
	return (ans);
}
