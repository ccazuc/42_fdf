/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:45:24 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/02 16:58:10 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*thread_run(void *data)
{
	t_thread	*thread;

	thread = (t_thread*)data;
	while (1)
	{
		pthread_mutex_lock(&thread->mutex);
		while (!thread->env->should_draw)
			pthread_cond_wait(&thread->env->thread_condition, &thread->mutex);
		draw_points(thread->env, thread, thread->start, thread->end);
		draw_all_lines(thread->env, thread, thread->start, thread->end);
		thread->draw_finished = 1;
		pthread_mutex_unlock(&thread->mutex);
	}
	return (NULL);
}

void	create_thread(t_env *env)
{
	int		i;

	if (!(env->thread_list = malloc(NB_THREAD * sizeof(*env->thread_list))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	i = -1;
	while (++i < NB_THREAD)
	{
		env->thread_list[i].env = env;
		env->thread_list[i].start = i * env->line_len / NB_THREAD;
		env->thread_list[i].end = (i + 1) * env->line_len / NB_THREAD;
		env->thread_list[i].id = i;
		env->thread_list[i].draw_finished = 1;
		pthread_mutex_init(&env->thread_list[i].mutex, NULL);
		pthread_mutex_lock(&env->thread_list[i].mutex);
		pthread_create(&env->thread_list[i].thread, NULL,
		thread_run, &env->thread_list[i]);
	}
}
