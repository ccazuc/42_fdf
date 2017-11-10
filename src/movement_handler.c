/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:40:46 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/10 16:40:27 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(t_env *env, float angle)
{
	reset_window(env);
	printf("prev_x: %d, prev_z: %d\n", env->position_x, env->position_z);
	env->position_x += cos(-angle / 180. * 3.14);
	env->position_z += sin(-angle / 180. * 3.14);
	printf("after_x: %d, after_z: %d\n", env->position_x, env->position_z);
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
