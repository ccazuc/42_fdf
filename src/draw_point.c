/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:08:42 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/02 16:53:34 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_points(t_env *env, t_thread *thread, int start, int end)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = -1;
	thread->bloc_drawn = 0;
	while (++i < env->nb_line)
	{
		j = start - 1;
		while (++j < end + 1 && ++j < env->line_len)
		{
			if (new_z(env, env->array[i][j]) > 0)
				continue ;
			if ((x = get_x_coordinate(env->arrat[i][j], env)) > WINDOW_WIDTH)
				continue ;
			if ((y = get_y_coordinate(env->array[i][j], env)) > WINDOW_HEIGHT)
				continue ;
			if (x >= 0 || y >= 0)
				continue ;
			++thread->bloc_drawn;
			pixel_put(env, x, y, get_color(env, env->array[i][j].y));
		}
	}
}
