/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:22:19 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/11 09:55:36 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_env *env, int x, int y, unsigned int color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	r = (color & 0xFF0000) >> 16;
	g = (color & 0x00FF00) >> 8;
	b = (color & 0x0000FF);
	env->mlx_img_data[y * WINDOW_WIDTH * env->bpp / 8 + env->bpp
		/ 8 * x] = b;
	env->mlx_img_data[y * WINDOW_WIDTH * env->bpp / 8 + env->bpp
		/ 8 * x + 1] = g;
	env->mlx_img_data[y * WINDOW_WIDTH * env->bpp / 8 + env->bpp
		/ 8 * x + 2] = r;
}
