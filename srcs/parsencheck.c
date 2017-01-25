/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsencheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfabre <rfabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 23:29:42 by rfabre            #+#    #+#             */
/*   Updated: 2017/01/25 21:19:58 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		ft_check_input_length(int lenght)
{
	if (lenght == 0 || (lenght + 1) % 21 != 0)
		ft_error_msg_exit("error");
}

void		ft_check_input_compo(char *str)
{
	int		i;
	int		count_dot;
	int		count_sharp;

	count_dot = 0;
	count_sharp = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			count_dot++;
		if (str[i] == '#')
			count_sharp++;
		i++;
	}
	if (count_dot == 12 && count_sharp == 4)
		;
	else
		ft_error_msg_exit("error");
}

void		ft_check_input_newline(char *str)
{
	int		i;
	int		count;

	count = 0;
	i = 4;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i += 5;
	}
	if (count != 4)
		ft_error_msg_exit("error");
}

void		ft_check_input_link(char *str)
{
	int		i;
	int		link_count;

	i = 0;
	link_count = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i - 1] == '#')
				link_count++;
			if (str[i + 1] == '#')
				link_count++;
			if (str[i + 5] == '#')
				link_count++;
			if (str[i + 5] == '#')
				link_count++;
		}
		i++;
	}
	if (link_count == 6 || link_count == 8)
		;
	else
		ft_error_msg_exit("error");
}

void		ft_input_checker(char **grid)
{
	int		i;

	i = 0;
	while (grid[i])
	{
		ft_check_input_length(ft_strlen(grid[i]));
		ft_check_input_compo(grid[i]);
		ft_check_input_newline(grid[i]);
		ft_check_input_link(grid[i]);
		i++;
	}
}
