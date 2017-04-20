/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shift.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:02:20 by rle               #+#    #+#             */
/*   Updated: 2017/04/18 20:24:36 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_y_shift(char **piece, t_dim dim)
{
	int	x;
	int	y;
	int	move;
	int	shift;

	y = 0;
	shift = 0;
	while (y < dim.piece.y)
	{
		x = 0;
		move = 1;
		while (piece[y][x])
		{
			if (piece[y][x] == '*')
				move = 0;
			x++;
		}
		if (move)
			shift++;
		else
			break ;
		y++;
	}
	return (shift);
}

int	get_x_shift(char **piece, t_dim dim)
{
	int	x;
	int	y;
	int	move;
	int	shift;

	x = 0;
	shift = 0;
	while (x < dim.piece.x)
	{
		y = 0;
		move = 1;
		while (y < dim.piece.y)
		{
			if (piece[y][x] == '*')
				move = 0;
			y++;
		}
		if (move)
			shift++;
		else
			break ;
		x++;
	}
	return (shift);
}
