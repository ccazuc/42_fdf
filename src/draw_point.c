/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:08:42 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/10 15:39:22 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_points(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->nb_line)
	{
			j = -1;
			while (++j < env->line_len)
				pixel_put(env, get_x_coordinate(env->array[i][j], env), get_y_coordinate(env->array[i][j], env), 16777215);
				//mlx_pixel_put(env->mlx_ptr, env->mlx_win, get_x_coordinate(env->array[i][j], env), get_y_coordinate(env->array[i][j], env), 16777215);
	}
}
