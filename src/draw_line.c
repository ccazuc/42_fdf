/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:27:02 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/02 16:53:59 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_env *env, t_thread *thread, t_line line)
{
	double	ratio;
	int		x;
	int		y;
	int		height;

	if ((line.src_x < 0 || line.dest_x > WINDOW_WIDTH) && (line.src_y < 0 ||
		line.src_y > WINDOW_HEIGHT))
		return ;
	ratio = .0;
	++thread->line_drawn;
	while (ratio <= 1)
	{
		height = line.p1.y + (line.p2.y - line.p1.y) * ratio;
		x = (int)(line.src_x + line.diff_x * ratio);
		y = (int)(line.src_y + line.diff_y * ratio);
		pixel_put(env, x, y, get_color(env, height));
		ratio += 1. / line.len;
	}
}

void	draw_line_prepare(t_env *env, t_thread *thread, t_point p1, t_point p2)
{
	t_line	line;

	if (new_z(env, p2) > 0 || new_z(env, p1) > 0)
		return ;
	line.src_x = get_x_coordinate(p1, env);
	line.dest_x = get_x_coordinate(p2, env);
	if (line.src_x < 0 && line.dest_x < 0)
		return ;
	if (line.src_x > WINDOW_WIDTH && line.dest_x > WINDOW_WIDTH)
		return ;
	line.dest_y = get_y_coordinate(p2, env);
	line.src_y = get_y_coordinate(p1, env);
	if (line.src_y < 0 && line.dest_y < 0)
		return ;
	if (line.src_y > WINDOW_HEIGHT && line.dest_y > WINDOW_HEIGHT)
		return ;
	line.diff_x = line.dest_x - line.src_x;
	line.diff_y = line.dest_y - line.src_y;
	line.p1 = p1;
	line.p2 = p2;
	line.len = sqrt(pow(line.diff_x, 2) + pow(line.diff_y, 2));
	draw_line(env, thread, line);
}

void	draw_all_lines(t_env *env, t_thread *thread, int start, int end)
{
	int		i;
	int		j;

	i = -1;
	thread->line_drawn = 0;
	while (++i < env->nb_line)
	{
		j = start - 1;
		while (++j < end + 1)
		{
			if (j < env->line_len - 1)
				draw_line_prepare(env, thread, env->array[i][j],
				env->array[i][j + 1]);
			if (i < env->nb_line - 1)
				draw_line_prepare(env, thread, env->array[i][j],
				env->array[i + 1][j]);
		}
	}
}
