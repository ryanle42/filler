/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:19:57 by rle               #+#    #+#             */
/*   Updated: 2017/04/18 19:10:50 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*clean_line(char *map)
{
	int		i;
	int		j;
	int		length;
	char	*tmp;

	i = 0;
	j = 4;
	length = ft_strlen(map) - 4;
	if (!(tmp = (char *)malloc(sizeof(char *) * length + 1)))
		return (NULL);
	while (i < length)
	{
		tmp[i] = map[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	free(map);
	return (tmp);
}

char	**get_map(t_coord coord)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * coord.y + 1);
	get_next_line(0, &map[0]);
	i = 0;
	while (i < coord.y)
	{
		get_next_line(0, &map[i]);
		map[i] = clean_line(map[i]);
		i++;
	}
	return (map);
}
