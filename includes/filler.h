/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 20:13:47 by rle               #+#    #+#             */
/*   Updated: 2017/05/06 12:43:04 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_dim
{
	t_coord		map;
	t_coord		piece;
	t_coord		ans;
	t_coord		shift;
}				t_dim;

typedef struct	s_data
{
	char		**map;
	char		**heatmap;
	char		**piece;
}				t_data;

typedef struct	s_player
{
	char		you;
	char		opp;
}				t_player;

typedef struct	s_dist
{
	int			best;
	int			tmp;
	t_player	player;
	t_coord		pos;
}				t_dist;

/*
**	init
*/

void			get_dim(t_coord *coord, int j);
t_player		get_player();
t_dim			make_dim();
void			zero_coord(t_coord *coord);
t_dist			init_dist(t_player player);

/*
**	get map
*/

char			*clean_line(char *map);
char			**get_map(t_coord dim);

/*
**	get piece
*/

char			**get_piece(t_coord dim);

/*
**	solver
*/

int				is_safe(t_data data, t_dim dim, t_player player, t_coord pos);
t_coord			place_piece(t_data data, t_dim dim, t_player player);
char			*convert_ans(t_coord pos, t_coord shift);

/*
**	distance formula
*/

int				dist_form(t_coord pos1, t_coord pos2);

/*
**	get shift
*/
int				get_y_shift(char **piece, t_dim dim);
int				get_x_shift(char **piece, t_dim dim);

/*
**	heatmap
*/
void			print_heat(char **heatmap, t_dim dim);
char			**prepare_heat(char **map, t_dim dim, t_player player);
char			**copy_map(char **map, t_dim dim);
void			make_heat(char **map, t_dim dim, char level, float fade);

#endif
