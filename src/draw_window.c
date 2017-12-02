/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:10:34 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/02 16:49:13 by ccazuc           ###   ########.fr       */
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

void	calc_stats(t_env *env)
{
	int		i;

	env->block_displayed = 0;
	i = -1;
	while (++i < NB_THREAD)
		env->block_displayed += env->thread_list[i].bloc_drawn;
	env->line_displayed = 0;
	i = -1;
	while (++i < NB_THREAD)
		env->line_displayed += env->thread_list[i].line_drawn;
}

void	draw_window(t_env *env)
{
	int		i;

	if (env->should_draw)
	{
		reset_window(env);
		i = -1;
		while (++i < NB_THREAD)
			env->thread_list[i].draw_finished = 0;
		pthread_cond_broadcast(&env->thread_condition);
		i = -1;
		while (++i < NB_THREAD)
			pthread_mutex_unlock(&env->thread_list[i].mutex);
		i = -1;
		while (++i < NB_THREAD)
			pthread_mutex_lock(&env->thread_list[i].mutex);
		calc_stats(env);
		env->should_draw = 0;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}

void	reset_window(t_env *env)
{
	unsigned int	len;

	len = WINDOW_WIDTH * WINDOW_HEIGHT * env->bpp / 8;
	ft_bzero(env->mlx_img_data, len);
}
