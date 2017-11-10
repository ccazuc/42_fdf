/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 07:55:03 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/10 11:34:24 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_env *env)
{
	int		i;
	int		j;

	if (!(env->mlx_ptr = mlx_init()))
		ft_exit("Error, failed to inti connection.", -1);
	if (!(env->mlx_win = mlx_new_window(env->mlx_ptr, WINDOW_WIDTH,
		WINDOW_HEIGHT, WINDOW_NAME)))
		ft_exit("Error, failed to create window.", -1);
	i = -1;
	while (++i < env->nb_line)
	{
		j = -1;
		while (++j < env->line_len)
			mlx_pixel_put(env->mlx_ptr, env->mlx_win, get_x_coordinate(env->array[i][j], env), get_y_coordinate(env->array[i][j], env), 16777215);
	}
	draw_all_lines(env);
	mlx_loop(env->mlx_ptr);
}
