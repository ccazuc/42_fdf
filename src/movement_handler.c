/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:40:46 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/02 16:52:36 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_scene(t_env *env, float angle)
{
	double	tmp;

	tmp = 0;
	if (!env->move_for && !env->move_back && !env->move_left &&
	!env->move_right)
		return ;
	if (env->move_for)
		tmp = 90;
	if (env->move_back)
		tmp = -90;
	if (env->move_left)
		tmp = 180;
	angle = env->rotation_y + tmp;
	printf("dx: %f\n", cos(-angle / 180.0 * 3.14));
	printf("tmp: %f\n", tmp);
	angle = 50;
	env->position_x += env->nb_line / 10 * cos(-angle / 180.0 * 3.14);
	env->position_z += env->nb_line / 10 * sin(-angle / 180.0 * 3.14);
}

void	move(t_env *env, float angle)
{
	angle = 5;
	if (!env->move_for && !env->move_back && !env->move_left &&
		!env->move_right && !env->move_cam_top && !env->move_cam_bot &&
		!env->move_cam_left && !env->move_cam_right && !env->space_down &&
		!env->drop_down)
		return ;
	if (env->move_for)
		env->position_z++;
	if (env->move_back)
		env->position_z--;
	if (env->move_left)
		env->position_x++;
	if (env->move_right)
		env->position_x--;
	env->should_draw = 1;
}
