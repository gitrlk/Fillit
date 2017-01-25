/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfabre <rfabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 20:42:01 by rfabre            #+#    #+#             */
/*   Updated: 2017/01/25 21:18:17 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_tetri_count(char **grid)
{
	int i;

	i = 0;
	while (grid[i])
		i++;
	return (i);
}

int			ft_max_size(int count)
{
	int max;

	max = 2;
	while (max * max < count * 4)
		max++;
	return (max);
}

void		ft_printstrs(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putstr(str[i]);
		ft_putchar('\n');
		i++;
	}
}

int			main(int argc, char **argv)
{
	int		i;
	char	**grid;
	t_coor	*coord;
	int		tetrinbr;
	char	**result;

	i = 0;
	if (argc != 2)
		ft_putstr("Fillit usage : ./fillit sample_file\n");
	else
	{
		grid = ft_read_input(argv[1]);
		ft_input_checker(grid);
		tetrinbr = ft_tetri_count(grid);
		coord = ft_get_coord(grid, tetrinbr);
		result = ft_solveit(coord, ft_max_size(tetrinbr), tetrinbr);
		ft_printstrs(result);
	}
	return (0);
}
