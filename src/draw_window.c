/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:10:34 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/11 09:10:42 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mod_zoom(t_env *env)
{
	if (env->is_unzoom == -1 && env->zoom == 1)
		return ;
	if (env->is_unzoom != -1 && env->zoom != 1)
		return ;
	env->should_draw = 1;
	env->zoom += env->is_zoom;
	env->zoom += env->is_unzoom;
}

void	draw_window(t_env *env)
{
	if (env->should_draw)
	{
		printf("Draw updated\n");
		draw_points(env);
		draw_all_lines(env);
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
