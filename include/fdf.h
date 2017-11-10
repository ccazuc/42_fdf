/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:29:32 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/10 08:04:18 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_HEIGHT 400
# define WINDOW_WIDTH 400
# define WINDOW_NAME "cc"

# include "../libft/libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "fcntl.h"
# include <stdio.h>

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

#endif
