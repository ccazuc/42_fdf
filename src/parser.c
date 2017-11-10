/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:19:47 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/10 17:41:38 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse(int argc, char **argv, t_env *env)
{
	int			fd;
	t_fdflist	*list;

	list = NULL;
	if (argc != 2)
		ft_exit("Error, incorrect number of argument.\n", -1);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_exit("Error, file not found.\n", -1);
	fill_datas_in_list(fd, &list, env);
	printf("call check_line_len\n");
	check_line_len(list, env);
	fill_datas_in_array(&list, env);
}

void	fill_datas_in_list(int fd, t_fdflist **list, t_env *env)
{
	char		*buffer;
	int			nb_line;

	nb_line = 0;
	while (get_next_line(fd, &buffer) == 1)
	{
		if (!*list)
			*list = create_elem(buffer);
		else
			list_push_back(list, buffer);
		++nb_line;
	}
	printf("nb_line: %d\n", nb_line);
	if (nb_line == 0)
		ft_exit("Error, empty file.", -1);
	env->nb_line = nb_line;
}

void	create_points(char *datas, t_env *env, int index)
{
	char	**tmp;
	int		i;
	t_point	*point;

	tmp = ft_strsplit(datas, ' ');
	i = -1;
	while (tmp[++i])
	{
		if (!(point = malloc(sizeof(*point))))
			ft_exit("Error, out of memory.", -1);
		point->x = i;
		point->y = ft_atoi(tmp[i]);
		point->z = index;
		if (point->y > env->max_height)
			env->max_height = point->y;
		if (point->y < env->min_height)
			env->min_height = point->y;
		env->array[point->z][point->x] = *point;
		free(point);
	}
}

void	fill_datas_in_array(t_fdflist **list, t_env *env)
{
	int			i;
	t_fdflist	*tmp_list;
	t_fdflist	*prev_list;

	printf("pre malloc\n");
	if (!(env->array = malloc(env->nb_line * sizeof(*env->array))))
		ft_exit("Error, out of memory.", -1);
	i = -1;
	printf("nb_line: %d\n", env->nb_line);
	while (++i < env->nb_line)
		if (!(env->array[i] = malloc(env->line_len * sizeof(**env->array))))
			ft_exit("Error, out of memory.", -1);
	i = -1;
	tmp_list = *list;
	while (++i < env->nb_line)
	{
		create_points(tmp_list->datas, env, i);
		prev_list = tmp_list;
		tmp_list = tmp_list->next;
		free(prev_list);
	}
}
