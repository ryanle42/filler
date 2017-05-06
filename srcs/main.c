/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:25:42 by rle               #+#    #+#             */
/*   Updated: 2017/05/05 13:52:03 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	print_heat(data.heatmap, dim, player);
*/

int	main(void)
{
	t_dim		dim;
	t_data		data;
	t_player	player;

	player = get_player();
	while (1)
	{
		dim = make_dim();
		get_dim(&dim.map, 0);
		data.map = get_map(dim.map);
		data.heatmap = copy_map(data.map, dim);
		data.heatmap = prepare_heat(data.heatmap, dim, player);
		make_heat(data.heatmap, dim, 9, 1.5);
		get_dim(&dim.piece, 1);
		data.piece = get_piece(dim.piece);
		dim.shift.y = get_y_shift(data.piece, dim);
		dim.shift.x = get_x_shift(data.piece, dim);
		dim.ans = place_piece(data, dim, player);
		ft_putstr_fd(convert_ans(dim.ans, dim.shift), 1);
	}
}
