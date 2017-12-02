/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 12:24:14 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/02 15:34:08 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env	*init_env(void)
{
	t_env	*env;

	if (!(env = malloc(sizeof(*env))))
		ft_exit("Error, out of memory.", -1);
	env->move_for = 0;
	env->move_back = 0;
	env->move_left = 0;
	env->move_right = 0;
	env->rotation_x = 120;
	env->rotation_y = 120;
	env->rotation_z = 120;
	env->position_x = 18;
	env->position_y = -40;
	env->position_z = 29;
	env->nb_tick = 0;
	env->zoom = 20;
	env->is_zoom = 0;
	env->is_unzoom = 0;
	env->should_draw = 1;
	env->last_time = time(NULL);
	env->fps = 0;
	env->can_draw = 0;
	pthread_cond_init(&env->thread_condition, NULL);
	return (env);
}
