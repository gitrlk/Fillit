/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfabre <rfabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 23:30:04 by rfabre            #+#    #+#             */
/*   Updated: 2017/01/25 21:19:12 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_check(char **grid, t_coor coord)
{
	int		y;
	int		x;
	int		i;

	y = 0;
	i = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[x])
		{
			if (coord.x[i] == x && coord.y[i] == y && grid[y][x] != '.')
				return (0);
			else if (coord.x[i] == x && coord.y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

t_coor		*ft_get_coord(char **grid, int count)
{
	t_coor	*result;
	int		i;
	int		pos;
	int		g;
	char	lettre;

	lettre = 'A';
	i = -1;
	result = (t_coor*)malloc(sizeof(t_coor) * count + 1);
	while (grid[++i])
	{
		result[i].lettre = lettre++;
		g = 0;
		pos = 0;
		while (grid[i][pos])
		{
			if (grid[i][pos] == '#')
			{
				result[i].x[g] = pos % 5;
				result[i].y[g++] = pos / 5;
			}
			pos++;
		}
	}
	return (result);
}

t_coor		ft_update_coord(t_coor coord, int x, int y)
{
	int		xmin;
	int		ymin;
	int		i;

	xmin = 500;
	ymin = 500;
	i = 0;
	while (i < 4)
	{
		if (coord.x[i] < xmin)
			xmin = coord.x[i];
		if (coord.y[i] < ymin)
			ymin = coord.y[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		coord.x[i] = coord.x[i] - xmin + x;
		coord.y[i] = coord.y[i] - ymin + y;
		i++;
	}
	return (coord);
}
