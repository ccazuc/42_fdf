/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:29:32 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/10 09:34:04 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_HEIGHT 800
# define WINDOW_WIDTH 800
# define X_ANGLE 160
# define Y_ANGLE 100
# define Z_ANGLE 100
# define WINDOW_NAME "cc"

# include "../libft/libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "fcntl.h"
# include <stdio.h>
# include <math.h>

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
}						t_point;

typedef struct			s_fdflist
{
	struct s_fdflist	*next;
	char				*datas;
}						t_fdflist;

typedef struct			s_env
{
	t_point				**array;
	int					nb_line;
	int					line_len;
	int					height;
	void				*mlx_ptr;
	void				*mlx_win;
}						t_env;

void					parse(int argc, char **argv, t_env *env);
void					fill_datas_in_list(int fd, t_fdflist **list, t_env *env);
void					fill_datas_in_array(t_fdflist **list, t_env *env);
void					check_line_len(t_fdflist *list, t_env *env);
t_fdflist				*create_elem(char *data);
void					list_push_back(t_fdflist **begin_list, char *data);
void					init_window(t_env *env);
int						get_x_coordinate(t_point point);
int						get_y_coordinate(t_point point);

#endif
