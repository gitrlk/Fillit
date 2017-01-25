/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfabre <rfabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 23:29:48 by rfabre            #+#    #+#             */
/*   Updated: 2017/01/25 21:19:00 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		*ft_input_split(char *str)
{
	int		i;

	i = 20;
	while (str[i])
	{
		if (str[i] == '\n' && (str[i + 1] == '.' || str[i + 1] == '#'))
			str[i] = '@';
		i += 21;
	}
	return (str);
}

char		**ft_read_input(char *str)
{
	int		fd;
	char	**grid;
	char	buf[BUF_SIZE + 1];

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error_msg_exit("error");
	read(fd, buf, BUF_SIZE);
	if (ft_strlen(buf) == 0)
		ft_error_msg_exit("error");
	ft_input_split(buf);
	grid = ft_strsplit(buf, '@');
	return (grid);
}
