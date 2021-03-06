/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:11:24 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/11 09:09:20 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		loop_handler(void *data)
{
	t_env	*env;

	env = data;
	move(env, 0);
	mod_zoom(env);
	env->nb_tick++;
	if (time(NULL) - env->last_time >= 1)
	{
		env->last_time = time(NULL);
		env->fps = env->nb_tick;
		env->nb_tick = 0;
	}
	draw_window(env);
	draw_ui(env);
	return (0);
}
