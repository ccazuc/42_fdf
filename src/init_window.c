/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 07:55:03 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/10 08:17:03 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_env *env)
{
	void	*mlx_ptr;
	void	*mlx_win;

	if (!(env->mlx_ptr = mlx_init()))
		ft_exit("Error, failed to inti connection.", -1);
	if (!(env->mlx_win = mlx_new_window(env->mlx_ptr, WINDOW_WIDTH,
		WINDOW_HEIGHT, WINDOW_NAME)))
		ft_exit("Error, failed to create window.", -1);
	//mlx_loop(env->mlx_ptr);
}
