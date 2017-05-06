/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:50:27 by rle               #+#    #+#             */
/*   Updated: 2017/04/18 19:13:46 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static long		squared(int n)
{
	return (n * n);
}

static float	absolute(float n)
{
	return (n < 0 ? -n : n);
}

static float	squareroot(int x)
{
	float	a;
	float	b;

	if (x < 0)
		return (0);
	a = 1;
	b = x;
	while (absolute(a - b) > (.1))
	{
		a = (a + b) / 2;
		b = x / a;
	}
	return (a);
}

int				dist_form(t_coord pos1, t_coord pos2)
{
	int	ans;

	ans = squareroot(squared(pos1.x - pos2.x) + squared(pos1.y - pos2.y));
	return (ans);
}
