/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfabre <rfabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 00:07:36 by rfabre            #+#    #+#             */
/*   Updated: 2017/01/25 21:18:06 by jecarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_error_msg_exit(char *message)
{
	ft_error_msg(message);
	exit(-1);
}

void	ft_error_msg(char *message)
{
	if (message)
		ft_putendl_fd(message, 1);
}
