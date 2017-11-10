/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:49:31 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/10 08:33:20 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_line_len(t_fdflist *list, t_env *env)
{
	t_fdflist	*tmp;
	int			last_len;
	int			len;

	printf("list: %p\n", list);
	tmp = list;
	printf("tmp: %p\n", tmp);
	last_len = -666;
	while (tmp)
	{
		len = ft_strlen(tmp->datas);
		if (last_len != -666 && len != last_len)
			ft_exit("Error, wrong line length.", -1);
		tmp = tmp->next;
		last_len = len;
	}
	if (last_len == -666)
		ft_exit("Error, wrong line length", -1);
	env->line_len = last_len;
}
