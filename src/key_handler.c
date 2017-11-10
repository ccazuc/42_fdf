/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:13:26 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/10 16:36:15 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_handler(int keycode, void *params)
{
	t_env *env;

	env = params;
	printf("Key Pressed: %d\n", keycode);
	if (keycode == 124 || keycode == 2)
		move_right(env);
	if (keycode == 125 || keycode == 1)
		move_backward(env);
	if (keycode == 126 || keycode == 13)
		move_forward(env);
	if (keycode == 123 || keycode == 0)
		move_left(env);
	if (params)
		return (0);
	return (0);
}
