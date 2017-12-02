/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:45:24 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/02 16:17:08 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*thread_run(void *data)
{
	t_thread	*thread;

	thread = (t_thread*)data;
	printf("thread %d started\n", thread->id);
	while (!thread->env->can_draw)
		//printf("can_draw: %d, thread: %d\n", thread->env->can_draw, thread->id);
		;
	printf("thead %d enter while(1)\n", thread->id);
	//pthread_mutex_lock(&thread->mutex);
	while (1)
	{
		//printf("thread %d pre_mutex_lock\n", thread->id);
		//printf("pos_x: %d, pos_y: %d\n", thread->env->position_x, thread->env->position_y);
		pthread_mutex_lock(&thread->mutex);
		//printf("thread %d post_mutex_lock\n", thread->id);
		while (!thread->env->should_draw)
			pthread_cond_wait(&thread->env->thread_condition, &thread->mutex);
		//printf("thread %d post cond_wait\n", thread->id);
		draw_points(thread->env, thread->start, thread->end);
		//printf("thread %d post draw_all_points\n", thread->id);
		draw_all_lines(thread->env, thread->start, thread->end);
		//printf("thread %d post draw_all_lines\n", thread->id);
		thread->draw_finished = 1;
		pthread_mutex_unlock(&thread->mutex);
		//printf("DRAW_FINISHED %d\n", thread->id);
		//printf("thread %d, post_mutex_unlock\n", thread->id);
	}
	return (NULL);
}

void	create_thread(t_env *env)
{
	int			i;

	i = -1;
	if (!(env->thread_list = malloc(NB_THREAD * sizeof(*env->thread_list))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	while (++i < NB_THREAD)
	{
		env->thread_list[i].env = env;
		env->thread_list[i].start = i * env->line_len / NB_THREAD;
		env->thread_list[i].end = (i + 1) * env->line_len / NB_THREAD;
		env->thread_list[i].id = i;
		env->thread_list[i].draw_finished = 1;
		pthread_mutex_init(&env->thread_list[i].mutex, NULL);
		pthread_mutex_lock(&env->thread_list[i].mutex);
		pthread_create(&env->thread_list[i].thread, NULL, thread_run, &env->thread_list[i]);
		printf("i: %d\n", i);
		//pthread_mutex_unlock(&env->thread_list[i].mutex);
	}
	printf("post pthread_create\n");
}

int		is_draw_finished(t_env *env)
{
	int		i;

	i = -1;
	while (++i < NB_THREAD)
		if (!env->thread_list[i].draw_finished)
			return (0);
	return (1);
}
