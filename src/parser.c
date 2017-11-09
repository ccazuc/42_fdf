/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:19:47 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/09 16:35:24 by ccazuc           ###   ########.fr       */
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
	fill_datas_in_list(fd, list, env);
	printf("call check_line_len\n");
	check_line_len(&list, env);
	fill_datas_in_array(&list, env);
}

void	add_datas(t_fdflist *list, char *buffer)
{
	t_fdflist	*result;
	t_fdflist	*tmp;

	if (!(result = malloc(sizeof(*list))))
		ft_exit("Error, out of memory.", -1);
	result->next = NULL;
	result->datas = buffer;
	if (!list)
	{
		list = result;
		return ;	
	}
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = result;	
}

void	fill_datas_in_list(int fd, t_fdflist *list, t_env *env)
{
	t_fdflist	*tmp;
	t_fdflist	*tmp_list;
	char		*buffer;
	int			nb_line;

	nb_line = 0;
	tmp_list = list;
	while (get_next_line(fd, &buffer) == 1)
	{
		add_datas(list, buffer);	
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

	(void)env;
	index++;
	tmp = ft_strsplit(datas, ' ');
	i = -1;
	while (tmp[++i])
		printf("point value: %d\n", ft_atoi(tmp[i]));	
}

void	fill_datas_in_array(t_fdflist **list, t_env *env)
{
	int			i;
	t_fdflist	*tmp_list;

	printf("pre malloc\n");
	if (!(env->array = malloc((env->nb_line + 1) * sizeof(*env->array))))
		ft_exit("Error, out of memory.", -1);
	env->array[env->nb_line] = 0;
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
		tmp_list = tmp_list->next;
	}
}
