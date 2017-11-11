/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:16:08 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/11 07:26:18 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
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
	env->position_x = 0;
	env->position_y = -20;
	env->position_z = 0;
	env->nb_tick = 0;
	env->zoom = 20;
	env->is_zoom = 0;
	env->is_unzoom = 0;
	env->last_time = time(NULL);
	env->fps = 0;
	parse(argc, argv, env);
	init_window(env);
}
