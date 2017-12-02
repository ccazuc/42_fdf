/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:08:42 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/11 13:24:15 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_points(t_env *env)
{
	int		i;
	int		j;
	int		x;
	int		y;

	env->block_displayed = 0;
	i = -1;
	while (++i < env->nb_line)
	{
		j = -1;
		while (++j < env->line_len)
		{
			if (new_z(env, env->array[i][j]) > 0)
				continue ;
			x = get_x_coordinate(env->array[i][j], env);
			if (x > WINDOW_WIDTH)
				continue ;
			y = get_y_coordinate(env->array[i][j], env);
			if (y > WINDOW_HEIGHT)
				continue ;
			if (x >= 0 && y >= 0)
			{
				++env->block_displayed;
				pixel_put(env, x, y, get_color(env, env->array[i][j].y));
			}
		}
	}
}
