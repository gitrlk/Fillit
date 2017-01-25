/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfabre <rfabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 23:29:55 by rfabre            #+#    #+#             */
/*   Updated: 2017/01/25 21:20:11 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		**ft_clean_grid(char **grid, t_coor coord)
{
	int		x;
	int		y;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == coord.lettre)
				grid[y][x] = '.';
			x++;
		}
		y++;
	}
	return (grid);
}

char		**ft_empty_grid(char **grid, int max)
{
	int		x;
	int		y;

	y = 0;
	if (!(grid = (char **)malloc(sizeof(char *) * (max + 1))))
		return (NULL);
	while (y < max)
	{
		grid[y] = (char *)malloc(sizeof(char) * (max + 1));
		x = 0;
		while (x < max)
		{
			grid[y][x] = '.';
			x++;
		}
		grid[y][x] = '\0';
		y++;
	}
	grid[y] = NULL;
	return (grid);
}

char		**ft_write(char **grid, t_coor coord)
{
	int		i;
	int		pos;
	int		g;

	i = 0;
	g = 0;
	while (grid[i])
	{
		pos = 0;
		while (grid[i][pos])
		{
			if (coord.x[g] == pos && coord.y[g] == i)
			{
				grid[i][pos] = coord.lettre;
				g++;
			}
			pos++;
		}
		i++;
	}
	return (grid);
}

char		**ft_fill(char **grid, t_coor *coord, int count, int i)
{
	int		x;
	int		y;
	char	**tmp;

	y = 0;
	if (i == count)
		return (grid);
	tmp = NULL;
	while (grid[y] && i < count)
	{
		x = 0;
		while (grid[y][x] && i < count)
		{
			coord[i] = ft_update_coord(coord[i], x, y);
			if (ft_check(grid, coord[i]) == 1)
				tmp = ft_fill(ft_write(grid, coord[i]), coord, count, (i + 1));
			if (tmp != NULL)
				return (tmp);
			grid = ft_clean_grid(grid, coord[i]);
			x++;
		}
		y++;
	}
	return (NULL);
}

char		**ft_solveit(t_coor *coord, int max, int count)
{
	char	**grid;

	grid = NULL;
	while (!grid)
	{
		grid = ft_empty_grid(grid, max);
		grid = ft_fill(grid, coord, count, 0);
		max++;
	}
	return (grid);
}
