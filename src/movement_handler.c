/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:40:46 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/10 17:22:49 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(t_env *env, float angle)
{
	angle = 5;
	reset_window(env);
	if (env->move_for)
		env->position_z++;
	if (env->move_back)
		env->position_z--;
	if (env->move_left)
		env->position_x++;
	if (env->move_right)
		env->position_x--;
	else
	{
		//printf("prev_x: %d, prev_z: %d\n", env->position_x, env->position_z);
		//env->position_x += cos(-angle / 180. * 3.14);
		//env->position_z += sin(-angle / 180. * 3.14);
		//printf("after_x: %d, after_z: %d\n", env->position_x, env->position_z);
	}
	draw_window(env);
}

void	move_forward(t_env *env)
{
	move(env, 90);
}

void	move_backward(t_env *env)
{
	move(env, -90);	
}

void	move_left(t_env *env)
{
	move(env, 180);
}

void	move_right(t_env *env)
{
	move(env, 0);	
}
