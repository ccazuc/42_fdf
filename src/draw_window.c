/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:10:34 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/10 16:37:31 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_window(t_env *env)
{
	draw_points(env);
	draw_all_lines(env);
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}

void	reset_window(t_env *env)
{
	unsigned int	i;
	unsigned int	len;

	len = WINDOW_WIDTH * WINDOW_HEIGHT * env->bpp / 8;
	printf("len: %d\n", len);
	i = 0;
	while (i < len)
	{
		env->mlx_img_data[i] = 0;
		++i;
	}
}