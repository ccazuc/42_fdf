/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:44:38 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/11 07:44:50 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_x_coordinate(t_point point, t_env *env)
{
	double	x;

	(void)env;
//	x = point.x * cos(ft_toradians(X_ANGLE)) + point.y * cos(ft_toradians(Y_ANGLE) + ft_toradians(120)) +
//		point.z * cos(ft_toradians(Z_ANGLE) - ft_toradians(120));
	//printf("y: %d\n", point.y);
	x = env->position_x + (point.x - point.z) / 1.32;
	return ((int)((x + 8) * env->zoom));
}

int		get_y_coordinate(t_point point, t_env *env)
{
	double y;

	(void)env;
	//y = point.x * sin(ft_toradians(X_ANGLE)) + point.y * sin(ft_toradians(Y_ANGLE) + ft_toradians(120)) +
	//	point.z * sin(ft_toradians(Z_ANGLE) - ft_toradians(120));
	y = env->position_z + (point.x + 2 * -point.y + point.z) / 2.5;
	return ((int)((y + 8) * env->zoom));
}

int		get_color(t_env *env, int y)
{
	int		part;

	if (y <= env->min_height)
		return (0xFF0000);
	if (y >= env->max_height)
		return (0xFFFF00);
	part = 0x00FF00 * (double)(y - env->min_height) / (double)(env->max_height
		- env->min_height);
	return (0xFF0000 + part - part % 0x00100);
}
