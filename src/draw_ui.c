/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:25:15 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/11 12:14:02 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_string(t_env *env, int x, int y, char *string)
{
	mlx_string_put(env->mlx_ptr, env->mlx_win, x, y, 0x0FFFFFF, string);
}

void	draw_information(t_env *env)
{
	char	*block_displayed;
	char	*line_displayed;

	block_displayed = ft_itoa(env->block_displayed);
	line_displayed = ft_itoa(env->line_displayed);
	draw_string(env, 5, 80, "Blocks displayed:");
	draw_string(env, 175, 80, block_displayed);
	draw_string(env, 5, 95, "Lines displayed:");
	draw_string(env, 165, 95, line_displayed);
	free(block_displayed);
	free(line_displayed);
}

void	draw_orientation(t_env *env)
{
	char	*x;
	char	*y;
	char	*z;

	x = ft_itoa(env->rotation_x);
	y = ft_itoa(env->rotation_y);
	z = ft_itoa(env->rotation_z);
	draw_string(env, 5, 110, "Orientation");
	draw_string(env, 5, 125, "X:");
	draw_string(env, 25, 125, x);
	draw_string(env, 5, 140, "Y:");
	draw_string(env, 25, 140, y);
	draw_string(env, 5, 155, "Z:");
	draw_string(env, 25, 155, z);
	free(x);
	free(y);
	free(z);
}

void	draw_position(t_env *env)
{
	char	*x;
	char	*y;
	char	*z;
	char	*fps;

	x = ft_itoa(env->position_x);
	y = ft_itoa(-env->position_y);
	z = ft_itoa(env->position_z);
	fps = ft_itoa(env->fps);
	draw_string(env, 5, 5, "Position:");
	draw_string(env, 5, 20, "X:");
	draw_string(env, 25, 20, x);
	draw_string(env, 5, 35, "Y:");
	draw_string(env, 25, 35, y);
	draw_string(env, 5, 50, "Z:");
	draw_string(env, 25, 50, z);
	draw_string(env, 5, 65, "Fps:");
	draw_string(env, 45, 65, fps);
	free(x);
	free(y);
	free(z);
	free(fps);
}

void	draw_ui(t_env *env)
{
	draw_position(env);
	draw_information(env);
	draw_orientation(env);
}
