/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 07:55:03 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/10 16:18:38 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_env *env)
{
	int		i;
	//int		j;
	int		line_size;
	int		bpp;
	int		order;

	if (!(env->mlx_ptr = mlx_init()))
		ft_exit("Error, failed to inti connection.", -1);
	if (!(env->mlx_win = mlx_new_window(env->mlx_ptr, WINDOW_WIDTH,
		WINDOW_HEIGHT, WINDOW_NAME)))
		ft_exit("Error, failed to create window.", -1);
	if (!(env->mlx_img = mlx_new_image(env->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT)))
		ft_exit("Error, failed to create image.", -1);
	line_size = WINDOW_WIDTH * 3;
	bpp = 24;
	order = 1;
	printf("pre_mlx_get_data_addr\n");
	if (!(env->mlx_img_data = mlx_get_data_addr(env->mlx_img, &bpp, &line_size, &order)))
		ft_exit("Error, failed to load image datas.", -1);
	i = -1;
	env->bpp = bpp;
	draw_window(env);
	mlx_key_hook(env->mlx_win, key_handler, env);
	mlx_loop(env->mlx_ptr);
}
