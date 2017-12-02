/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:44:38 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/11 12:52:47 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double			new_x(t_env *env, t_point point)
{
	double	x;

	x = cos(env->rotation_y / 180.0 * 3.14)
		* (point.x - env->position_x)
		- sin(env->rotation_y / 180.0 * 3.14)
		* ((point.z - env->position_z) + env->max_height);
	return (x * 50);
}

double			new_y(t_env *env, t_point point)
{
	double	y;

	y = sin(env->rotation_x / 180.0 * 3.14)
		* (cos(env->rotation_y / 180.0 * 3.14)
		* ((point.z - env->position_z) + env->max_height)
		+ sin(env->rotation_y / 180.0 * 3.14)
		* (point.x - env->position_x))
		+ cos(env->rotation_x / 180.0 * 3.14)
		* (-point.y - env->position_y);
	return (y * 50);
}

double			new_z(t_env *env, t_point point)
{
	double	z;

	z = cos(env->rotation_x / 180.0 * 3.14)
		* (cos(env->rotation_y / 180.0 * 3.14)
		* ((point.z - env->position_z) + env->max_height)
		+ sin(env->rotation_y / 180.0 * 3.14)
		* (point.x - env->position_x))
		- sin(env->rotation_x / 180.0 * 3.14)
		* (-point.y - env->position_y);
	return (z / 10);
}

int				get_x_coordinate(t_point point, t_env *env)
{
	double	n_x;
	double	n_z;

	n_x = new_x(env, point);
	n_z = new_z(env, point);
	//printf("x: %f, n_x: %f, n_z: %f\n", WINDOW_WIDTH / 2 + n_x / n_z, n_x, n_z);
	if (n_z == 0)
		n_z = 1;
	return (WINDOW_WIDTH / 2 + n_x * env->zoom / 20 / n_z);
}

int				get_y_coordinate(t_point point, t_env *env)
{
	double	n_y;
	double	n_z;

	n_y = new_y(env, point);
	n_z = new_z(env, point);
	if (n_z == 0)
		n_z = 1;
	//printf("y: %f, n_y,: %f, n_z: %f\n", WINDOW_HEIGHT / 2 + n_y / n_z, n_y, n_z);
	return (WINDOW_HEIGHT / 2 + n_y * env->zoom / 20 / n_z);
}

int		get_color(t_env *env, int y)
{
	int		part;

	if (y <= env->min_height)
		return (0xFF0000);
	if (y >= env->max_height)
		return (0xFFFF00);
	part = 0x00FF00 * (double)(y - env->min_height) / (double)(env->max_height - env->min_height);
	return (0xFF0000 + part - part % 0x00900);	
}
