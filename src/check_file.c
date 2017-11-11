/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:49:31 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/11 09:56:09 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_line_len(char *datas)
{
	char	**tmp;
	int		i;

	tmp = ft_strsplit(datas, ' ');
	if (!tmp)
		return (0);
	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
	return (i);
}

void	check_line_len(t_fdflist *list, t_env *env)
{
	t_fdflist	*tmp;
	int			last_len;
	int			len;

	tmp = list;
	last_len = -666;
	while (tmp)
	{
		len = get_line_len(tmp->datas);
		printf("len: %d\n", len);
		if (last_len != -666 && len != last_len)
		{
			printf("last_len: %d, len: %d\n", last_len, len);
			ft_exit("Error, wrong line length.", -1);
		}
		tmp = tmp->next;
		last_len = len;
	}
	if (last_len == -666)
		ft_exit("Error, wrong line length", -1);
	env->line_len = len;
}
