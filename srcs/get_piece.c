/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:36:06 by rle               #+#    #+#             */
/*   Updated: 2017/04/18 19:11:24 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**get_piece(t_coord coord)
{
	char	**piece;
	int		i;

	piece = (char **)malloc(sizeof(char *) * coord.y);
	i = 0;
	while (i < coord.y)
	{
		get_next_line(0, &piece[i]);
		i++;
	}
	return (piece);
}
