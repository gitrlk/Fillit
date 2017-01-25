/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfabre <rfabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 23:30:17 by rfabre            #+#    #+#             */
/*   Updated: 2017/01/25 20:12:26 by rfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 4096
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "../LIBFT/libft.h"

typedef struct		s_coor
{
	char	lettre;
	int		x[4];
	int		y[4];
}					t_coor;

void				ft_check_input_length(int lenght);
void				ft_check_input_compo(char *str);
void				ft_check_input_newline(char *str);
void				ft_check_input_link(char *str);
void				ft_input_checker(char **grid);
char				*ft_input_split(char *str);
char				**ft_read_input(char *str);
int					ft_tetri_count(char **grid);
int					ft_max_size(int count);
void				ft_printstrs(char **str);
void				ft_error_msg_exit(char *message);
void				ft_error_msg(char *message);
int					ft_check(char **grid, t_coor coord);
t_coor				*ft_get_coord(char **grid, int count);
t_coor				ft_update_coord(t_coor coord, int x, int y);
char				**ft_clean_grid(char **grid, t_coor coord);
char				**ft_empty_grid(char **grid, int max);
char				**ft_write(char **grid, t_coor coord);
char				**ft_fill(char **grid, t_coor *coord, int count, int i);
char				**ft_solveit(t_coor *coord, int max, int count);
#endif
