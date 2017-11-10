/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:08:42 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/10 18:34:55 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_points(t_env *env)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = -1;
	while (++i < env->nb_line)
	{
			j = -1;
			while (++j < env->line_len)
			{
				x = get_x_coordinate(env->array[i][j], env);
				if (x > WINDOW_WIDTH)
					continue ;
				y = get_y_coordinate(env->array[i][j], env);
				if (y > WINDOW_HEIGHT)
					return ;
				if (x >= 0 && y >= 0)
					pixel_put(env, x, y, get_color(env, env->array[i][j].y));
			}
				//mlx_pixel_put(env->mlx_ptr, env->mlx_win, get_x_coordinate(env->array[i][j], env), get_y_coordinate(env->array[i][j], env), 16777215);
	}
}
