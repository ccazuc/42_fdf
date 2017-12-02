/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:13:26 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/02 16:12:36 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_down_handler_bis(int keycode, t_env *env)
{
	if (keycode == 124)
		env->move_cam_right = 1;
	else if (keycode == 125)
		env->move_cam_bot = 1;
	else if (keycode == 126)
		env->move_cam_top = 1;
	else if (keycode == 123)
		env->move_cam_left = 1;
	else if (keycode == 6)
		env->drop_down = 1; 
}

int		key_down_handler(int keycode, void *params)
{
	t_env *env;

	env = params;
	//printf("Key Down: %d\n", keycode);
	if (keycode == 2)
		env->move_right = 1;
	else if (keycode == 1)
		env->move_back = 1;
	else if (keycode == 13)
		env->move_for = 1;
	else if (keycode == 0)
		env->move_left = 1;
	else if (keycode == 69 || keycode == 24)
		env->is_zoom = 1;
	else if (keycode == 78 || keycode == 27)
		env->is_unzoom = -1;
	else if (keycode == 49)
		env->space_down = 1;
	key_down_handler_bis(keycode, env);
	return (0);
}

void	key_up_handler_bis(int keycode, t_env *env)
{	
	if (keycode == 124)
		env->move_cam_right = 0;
	else if (keycode == 125)
		env->move_cam_bot = 0;
	else if (keycode == 126)
		env->move_cam_top = 0;
	else if (keycode == 123)
		env->move_cam_left = 0;
	else if (keycode == 6)
		env->drop_down = 0;
}

int		key_up_handler(int keycode, void *params)
{
	t_env *env;

	env = params;
	//printf("Key Up: %d\n", keycode);
	if (keycode == 2)
		env->move_right = 0;
	else if (keycode == 1)
		env->move_back = 0;
	else if (keycode == 13)
		env->move_for = 0;
	else if (keycode == 0)
		env->move_left = 0;
	else if (keycode == 69 || keycode == 24)
		env->is_zoom = 0;
	else if (keycode == 78 || keycode == 27)
		env->is_unzoom = 0;
	else if (keycode == 53)
		ft_exit("Exit requested.", 0);
	else if (keycode == 49)
		env->space_down = 0;
	key_up_handler_bis(keycode, env);
	return (0);
}
