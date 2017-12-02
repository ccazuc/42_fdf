/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:29:32 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/02 16:56:51 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920
# define X_ANGLE 160
# define Y_ANGLE 100
# define Z_ANGLE 100
# define WINDOW_NAME "cc"
# define NB_THREAD 10

# include "../libft/libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "fcntl.h"
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <pthread.h>

typedef struct			s_thread t_thread;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
}						t_point;

typedef struct			s_line
{
	int					dest_x;
	int					dest_y;
	int					src_x;
	int					src_y;
	int					diff_x;
	int					diff_y;
	int					len;
	struct s_point		p1;
	struct s_point		p2;
}						t_line;

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
	void				*mlx_img;
	char				*mlx_img_data;
	int					position_x;
	int					position_y;
	int					position_z;
	int					rotation_x;
	int					rotation_y;
	int					rotation_z;
	int					bpp;
	int					move_for;
	int					move_back;
	int					move_left;
	int					move_right;
	int					min_height;
	int					max_height;
	time_t				last_time;
	int					nb_tick;
	int					fps;
	int					zoom;
	int					is_zoom;
	int					is_unzoom;
	int					should_draw;
	int					block_displayed;
	int					line_displayed;
	int					move_cam_top;
	int					move_cam_bot;
	int					move_cam_left;
	int					move_cam_right;
	int					space_down;
	int					drop_down;
	t_thread			*thread_list;
	pthread_cond_t		thread_condition;
	int					can_draw;
}						t_env;

typedef struct			s_thread
{
	int					start;
	int					end;
	t_env				*env;
	pthread_t			thread;
	pthread_mutex_t		mutex;
	int					bloc_drawn;
	int					line_drawn;
	int					id;
	int					draw_finished;
}						t_thread;	

void					parse(int argc, char **argv, t_env *env);
void					fill_datas_in_list(int fd, t_fdflist **list,
						t_env *env);
void					fill_datas_in_array(t_fdflist **list, t_env *env);
void					check_line_len(t_fdflist *list, t_env *env);
t_fdflist				*create_elem(char *data);
void					list_push_back(t_fdflist **begin_list, char *data);
void					init_window(t_env *env);
int						get_x_coordinate(t_point point, t_env *env);
int						get_y_coordinate(t_point point, t_env *env);
void					draw_all_lines(t_env *env, t_thread *thread, int start, int end);
void					pixel_put(t_env *env, int x, int y, unsigned int color);
void					draw_window(t_env *env);
void					draw_points(t_env *env, t_thread *thread, int start, int end);
void					move(t_env *env, float angle);
void					reset_window(t_env *env);
int						loop_handler(void *datas);
int						key_down_handler(int keycode, void *datas);
int						key_up_handler(int keycode, void *datas);
void					draw_ui(t_env *env);
int						get_color(t_env *env, int y);
void					mod_zoom(t_env *env);
double					new_x(t_env *env, t_point point);
double					new_y(t_env *env, t_point point);
double					new_z(t_env *env, t_point point);
void					create_thread(t_env *env);
t_env					*init_env(void);

#endif
