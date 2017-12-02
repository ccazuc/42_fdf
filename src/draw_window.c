/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:10:34 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/02 16:15:59 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mod_zoom(t_env *env)
{
	if (env->is_unzoom != -1 && env->is_zoom != 1)
		return ;
	env->should_draw = 1;
	env->zoom += env->is_zoom;
	env->zoom += env->is_unzoom;
}

void	draw_window(t_env *env)
{
	int		i;

	if (env->should_draw)
	{
		//printf("draw start\n");
		reset_window(env);
		i = -1;
		while (++i < NB_THREAD)
			env->thread_list[i].draw_finished = 0;
		pthread_cond_broadcast(&env->thread_condition);
		i = -1;
		while (++i < NB_THREAD)
			pthread_mutex_unlock(&env->thread_list[i].mutex);

		//draw_points(env, 0, env->line_len);
		//draw_all_lines(env, 0, env->line_len);
		//printf("draw pre cond_broadcast\n");
		//pthread_cond_broadcast(&env->thread_condition);
		//printf("draw post cond_broadcast\n");
		//pthread_mutex_unlock(&env->thread_list[i].mutex);

		i = -1;
		while (++i < NB_THREAD)
			pthread_mutex_lock(&env->thread_list[i].mutex);
		env->should_draw = 0;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}

void	reset_window(t_env *env)
{
	unsigned int	i;
	unsigned int	len;

	len = WINDOW_WIDTH * WINDOW_HEIGHT * env->bpp / 8;
	i = 0;
	while (i < len)
	{
		env->mlx_img_data[i] = 0;
		++i;
	}
}
