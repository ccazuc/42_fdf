/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:25:15 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/10 18:00:48 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_string(t_env *env, int x, int y, char *string)
{
	mlx_string_put(env->mlx_ptr, env->mlx_win, x, y, 0x0FFFFFF, string);
}

void	draw_position(t_env *env)
{
	char	*x;
	char	*y;
	char	*fps;

	x = ft_itoa(-env->position_x);
	y = ft_itoa(-env->position_z);
	fps = ft_itoa(env->fps);
	draw_string(env, 5, 5, "Position:");
	draw_string(env, 5, 20, "X:");
	draw_string(env, 25, 20, x);
	draw_string(env, 5, 35, "Y:");
	draw_string(env, 25, 35, y);
	draw_string(env, 5, 50, "Fps:");
	draw_string(env, 45, 50, fps);
	free(x);
	free(y);
	free(fps);
}

void	draw_ui(t_env *env)
{
	draw_position(env);	
}
