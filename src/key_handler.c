/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:13:26 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/11 07:27:07 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_down_handler(int keycode, void *params)
{
	t_env *env;

	env = params;
	printf("Key Down: %d\n", keycode);
	if (keycode == 124 || keycode == 2)
		env->move_right = 1;
	if (keycode == 125 || keycode == 1)
		env->move_back = 1;
	if (keycode == 126 || keycode == 13)
		env->move_for = 1;
	if (keycode == 123 || keycode == 0)
		env->move_left = 1;
	if (keycode == 69 || keycode == 24)
		env->is_zoom = 1;
	if (keycode == 78 || keycode == 27)
		env->is_unzoom = -1;
	return (0);
}

int		key_up_handler(int keycode, void *params)
{
	t_env *env;

	env = params;
	printf("Key Up: %d\n", keycode);
	if (keycode == 124 || keycode == 2)
		env->move_right = 0;
	if (keycode == 125 || keycode == 1)
		env->move_back = 0;
	if (keycode == 126 || keycode == 13)
		env->move_for = 0;
	if (keycode == 123 || keycode == 0)
		env->move_left = 0;
	if (keycode == 69 || keycode == 24)
		env->is_zoom = 0;
	if (keycode == 78 || keycode == 27)
		env->is_unzoom = 0;
	if (keycode == 53)
		ft_exit("Exit requested.", 0);
	return (0);
}
